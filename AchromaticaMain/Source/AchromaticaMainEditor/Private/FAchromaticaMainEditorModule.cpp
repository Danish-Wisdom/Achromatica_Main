#include "AuraDataTableUtility.h"
#include "ContentBrowserModule.h"
#include "IContentBrowserSingleton.h"
#include "Modules/ModuleManager.h"

class FAchromaticaMainEditorModule : public IModuleInterface
{
	TSharedPtr<FExtender> MenuExtender;
public:

	virtual void StartupModule() override
	{
		FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");

		MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension(
			"GetAssetActions",
			EExtensionHook::After,
			nullptr,
			FMenuExtensionDelegate::CreateRaw(this, &FAchromaticaMainEditorModule::AddMenuEntry)
		);
		

		ContentBrowserModule.GetAllAssetViewContextMenuExtenders().Add(
			FContentBrowserMenuExtender_SelectedAssets::CreateRaw(
				this, &FAchromaticaMainEditorModule::OnExtendContentBrowserMenu));

		
	}

	virtual void ShutdownModule() override
	{
		// if (FModuleManager::Get().IsModuleLoaded("ContentBrowser"))
		// {
		// 	FContentBrowserModule& ContentBrowserModule = FModuleManager::GetModuleChecked<FContentBrowserModule>("ContentBrowser");
		// 	ContentBrowserModule.GetAllAssetViewContextMenuExtenders().Remove(
		// 		FContentBrowserMenuExtender_SelectedAssets::CreateRaw(
		// 		this, &FAchromaticaMainEditorModule::OnExtendContentBrowserMenu));
		// }
	}

	TSharedRef<FExtender> OnExtendContentBrowserMenu(const TArray<FAssetData>& SelectedAssets)
	{
		return MenuExtender.ToSharedRef();
	}

	void AddMenuEntry(FMenuBuilder& MenuBuilder)
	{
		MenuBuilder.AddMenuEntry(
			FText::FromString("Convert to AuraDataTable"),
			FText::FromString("Create a UAuraDataTable copy of this DataTable"),
			FSlateIcon(),
			FExecuteAction::CreateRaw(this, &FAchromaticaMainEditorModule::OnConvertSelected)
		);
	}

	void OnConvertSelected()
	{
		FContentBrowserModule& ContentBrowserModule =
			FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
		TArray<FAssetData> SelectedAssets;
		ContentBrowserModule.Get().GetSelectedAssets(SelectedAssets);

		for (const FAssetData& SelectedAsset : SelectedAssets)
		{
			if (UDataTable* Table = Cast<UDataTable>(SelectedAsset.GetAsset()))
			{
				UAuraDataTableUtility::ConvertToAuraDataTable(Table);
			}
		}
	}
};

IMPLEMENT_MODULE(FAchromaticaMainEditorModule, AchromaticaMainEditor);