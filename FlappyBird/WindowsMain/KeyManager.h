#pragma once
using KeyType = int32;
enum class KeyState
{
	None,
	Press,
	Down,
	Up,
	End
};
enum
{
	KEY_TYPE_COUNT=static_cast<int32>(256),
	KEY_STATE_COUNT=static_cast<int32>(KeyState::End)
};
class KeyManager
{
	DECLARE_SINGLE(KeyManager)
private:
	vector<KeyState> _states;
public:
	//current frame
	bool GetKeyDown(KeyType key);
	bool GetKey(KeyType key);
	bool GetKeyUp(KeyType key);

public:
	void Init();
	void Update();
	void Release();


};
