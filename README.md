# CubiquityTest

Unreal Engine 4 test project for Cubiquity

> Cubiquity is in pre-alpha development

## Getting started

If you havn't used Cubiquity for UE4 before there are a two steps you have to do, before use.

1. You have to edit two or three files depending on what volumes you are going to use. 
All files we are going to edit is under Cubiquity plugin folder.

	* Change 'ThirdPartyPath' property in [Cubiquity.Build.cs][1.0] to where 'Cubiquity-2015-06-14' folder is located. This can also be found in this repository, [here][deps].

		```cs
	    private string ThirdPartyPath
	    {
	        get { return Path.GetFullPath(@"[Cubiquity-UE4-Test]\Plugins\Cubiquity-Dependencies\Cubiquity-2015-06-14"); } // TODO: Edit this line to match where Cubiquity is installed
	    }
		```

	* Change 'volumeFileName' field which is located in [CubiquityColoredCubesVolume][1.1] and [CubiquityTerrainVolume][1.2] constructors. They should target where the vdb files are so it will load a volume.

		```cpp
		ACubiquityColoredCubesVolume::ACubiquityColoredCubesVolume(const FObjectInitializer& PCIP)
			: Super(PCIP)
		{
			volumeFileName = "[Cubiquity-UE4-Test]\Plugins\Cubiquity-Dependencies\example-vdb\VoxeliensTerrain.vdb";
		}
		```

		```cpp
		ACubiquityTerrainVolume::ACubiquityTerrainVolume(const FObjectInitializer& PCIP)
			: Super(PCIP)
		{
			volumeFileName = TEXT("[Cubiquity-UE4-Test]\Plugins\Cubiquity-Dependencies\example-vdb\SmoothVoxeliensTerrain.vdb");
		}
		```

2. The last thing that you have to do is download [CubiquityColoredCubesVertexFactory.usf][2.0] and save it to 'UnrealEngine/Engine/Shaders' in UnrealEngine's main folder. For example "C:\Program Files\Epic Games\4.8\Engine\Shaders".


[deps]: https://github.com/ChillyFlashER/Cubiquity-UE4-Test/tree/master/Plugins/Cubiquity-Dependencies
[1.0]: https://github.com/ChillyFlashER/cubiquity-for-unreal-engine/blob/master/Source/Cubiquity/Cubiquity.Build.cs
[1.1]: https://github.com/ChillyFlashER/cubiquity-for-unreal-engine/blob/master/Source/Cubiquity/Private/CubiquityColoredCubesVolume.cpp
[1.2]: https://github.com/ChillyFlashER/cubiquity-for-unreal-engine/blob/master/Source/Cubiquity/Private/CubiquityTerrainVolume.cpp
[2.0]: http://www.volumesoffun.com/downloads/Cubiquity/CubiquityColoredCubesVertexFactory.usf
