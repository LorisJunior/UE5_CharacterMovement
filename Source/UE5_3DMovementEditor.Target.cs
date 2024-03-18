// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class UE5_3DMovementEditorTarget : TargetRules
{
	public UE5_3DMovementEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "UE5_3DMovement" } );
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;
	}
}
