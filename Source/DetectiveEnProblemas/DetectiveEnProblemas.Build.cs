// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DetectiveEnProblemas : ModuleRules
{
	public DetectiveEnProblemas(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput",  "Paper2D"  });
	}
}
