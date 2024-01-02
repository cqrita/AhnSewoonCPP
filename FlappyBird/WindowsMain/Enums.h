#pragma once
//enum
enum class SceneType
{
	None,
	Dev1Scene,
	Dev2Scene,
	MapToolScene,
	MenuScene
};

enum class ColliderType
{
	None,
	Box,
	Circle
};
enum class LayerType
{
	 Background,
	 Object,

	 End
};
namespace eCounter
{
	const int LAYER_MAXCOUNT = static_cast<int>(LayerType::End);
}
enum CollisionLayerType : uint8
{
	CLT_OBJECT,
	CLT_WALL,
};
enum class ItemBoxType
{
	HPItemBox,
	MissileItemBox,
	None
};