// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TgJam : ModuleRules
{
	public TgJam(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
