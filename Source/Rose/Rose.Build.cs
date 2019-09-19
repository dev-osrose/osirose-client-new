// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.IO;
using System;

public class Rose : ModuleRules
{

    private string ModulePath
    {
        get { return ModuleDirectory; }
    }

    private string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty/")); }
    }

	public Rose(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true

        LoadOsiroseLib(Target);
	}

    public bool LoadOsiroseLib(ReadOnlyTargetRules Target)
    {
        bool isLibrarySupported = true;

        if (Target.Platform == UnrealTargetPlatform.Win64 || Target.Platform == UnrealTargetPlatform.Win32)
        {
            isLibrarySupported = true;
            string PlateformLib = Target.Platform == UnrealTargetPlatform.Win64 ? "x64" : "x86";
            string LibrariesPath = Path.Combine(ThirdPartyPath, "Osirose", "Libraries");

            Console.WriteLine("Libraries path " + LibrariesPath);

            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "RoseCommon.lib")); // add x64 / x86 ?
        }
        // add linux / mac support?
        if (isLibrarySupported)
        {
            PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "Osirose", "Includes"));
            PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "Osirose", "Includes", "rosecommon"));
            PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "Osirose", "Includes", "core"));
        }

        return isLibrarySupported;
    }
}
