// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Opti17979 : ModuleRules
{
	public Opti17979(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Opti17979",
			"Opti17979/Variant_Platforming",
			"Opti17979/Variant_Platforming/Animation",
			"Opti17979/Variant_Combat",
			"Opti17979/Variant_Combat/AI",
			"Opti17979/Variant_Combat/Animation",
			"Opti17979/Variant_Combat/Gameplay",
			"Opti17979/Variant_Combat/Interfaces",
			"Opti17979/Variant_Combat/UI",
			"Opti17979/Variant_SideScrolling",
			"Opti17979/Variant_SideScrolling/AI",
			"Opti17979/Variant_SideScrolling/Gameplay",
			"Opti17979/Variant_SideScrolling/Interfaces",
			"Opti17979/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
