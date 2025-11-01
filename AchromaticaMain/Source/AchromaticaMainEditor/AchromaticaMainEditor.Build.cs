using UnrealBuildTool;

public class AchromaticaMainEditor : ModuleRules
{
	public AchromaticaMainEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		bUsePrecompiled = false;

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"UnrealEd",               // for editor asset handling
			"AssetRegistry",
			"ContentBrowser",
			"AssetTools",
			"Slate",
			"SlateCore",
			"EditorSubsystem",
			"Blutility",
			"EditorScriptingUtilities", 
			"AchromaticaMain"		// your main game module
		});
		
		PublicIncludePaths.AddRange(new string[] {
			"AchromaticaMainEditor/Public"
		});

		PrivateIncludePaths.AddRange(new string[] {
			"AchromaticaMainEditor/Private"
		});
	}
	
}