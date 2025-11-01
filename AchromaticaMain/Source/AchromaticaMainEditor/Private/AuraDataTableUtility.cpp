// Fill out your copyright notice in the Description page of Project Settings.


#include "AchromaticaMainEditor/Public/AuraDataTableUtility.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "EditorAssetLibrary.h"
#include "Misc/PackageName.h"
#include "UObject/SavePackage.h"

#define LOG(x) UE_LOG(LogTemp, Display, TEXT(x))

UAuraDataTable* UAuraDataTableUtility::ConvertToAuraDataTable(UDataTable* SourceTable)
{
#if WITH_EDITOR
	if (!SourceTable)
	{
		LOG("No Valid DataTable provided.")
		return nullptr;
	}

	
	// Paths and Names
	FString OldPath = SourceTable->GetPathName();
	FString PackagePath = FPackageName::ObjectPathToPackageName(OldPath);
	FString FolderPath = FPaths::GetPath(PackagePath);
	FString NewAssetName = SourceTable->GetName() + TEXT("_AuraTable");
	FString NewPackagePath = FolderPath / NewAssetName;


	// New Package and AuraDataTable
	UPackage* NewPackage = CreatePackage(*NewPackagePath);
	UAuraDataTable* NewTable = NewObject<UAuraDataTable>(
		NewPackage,
		*NewAssetName,
		RF_Public | RF_Standalone
	);

	UScriptStruct* TempRowStruct = const_cast<UScriptStruct*>(SourceTable->GetRowStruct());

	if (!TempRowStruct) return nullptr;
	
	NewTable->RowStruct = TempRowStruct;

	const TMap<FName, uint8*>& SourceMap = SourceTable->GetRowMap();
	for (const TPair<FName, uint8*>& Pair : SourceMap)
	{
		const FName RowName = Pair.Key;
		uint8* SrcData = Pair.Value;

		if (!SrcData) continue;

		// Allocalte memory
		const int32 RowSize = TempRowStruct->GetStructureSize();
		uint8* TempMemory = static_cast<uint8*>(FMemory::Malloc(RowSize));
		TempRowStruct->InitializeStruct(TempMemory);
		TempRowStruct->CopyScriptStruct(TempMemory, SrcData);

		const FTableRowBase* RowBase = reinterpret_cast<FTableRowBase*>(TempMemory);
		NewTable->AddRow(RowName, *RowBase);

		TempRowStruct->DestroyStruct(TempMemory);
		FMemory::Free(TempMemory);
	}

	FAssetRegistryModule::AssetCreated(NewTable);

	NewPackage->MarkPackageDirty();

	NewTable->PostEditChange();

	// Optionally save package to disk immediately (uncomment if desired)
	const FString PackageFileName = FPackageName::LongPackageNameToFilename(NewPackagePath, FPackageName::GetAssetPackageExtension());
	FSavePackageArgs Args = FSavePackageArgs();
	Args.TopLevelFlags = EObjectFlags::RF_Public | EObjectFlags::RF_Standalone;
	bool bSaved = UPackage::SavePackage(NewPackage, NewTable, *PackageFileName, Args);

	UE_LOG(LogTemp, Log, TEXT("Created UWeaponDataTable '%s' with %d rows"), *NewAssetName, NewTable->GetRowMap().Num());

	return NewTable;

#endif
	return nullptr;
}
