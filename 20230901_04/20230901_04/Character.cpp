#include "stdafx.h"
#include "Character.h"

void Character::Init()
{
    _x = 10;
    _y = 9; // Initial position adjusted for the floor
    _animationIndex = 0;
    _animationTime = 0;
    _isJumping = false;
    _isAir = false;
    _jumpDuration = 30; // Set the jump duration (milliseconds)
    _jumpTimer = 0;
}

void Character::Update(int deltaTime, char inputKey)
{
    // Character movement code
    
    switch (inputKey)
    {
    case 'w':
        Jump();
        break;
    case 'a':
        Move(-1);
        break;
    case 'd':
        Move(1);
        break;
    default:
        break;
    }
    

    

    if (_isJumping == true)
    {
        _jumpTimer += deltaTime;
        if (_jumpTimer > _jumpDuration)
        {
            Erase();
            if (_isAir==true)
            {
                _y--;
                if (_y < 2)
                {
                    _isAir = false;
                }
            }
            else
            {
                _y++;
                if (_y > 8)
                {
                    _isJumping = false;
                }
            }
            _jumpTimer = 0;
        }
    }
    // Character animation code
    _animationTime += deltaTime;
    if (_animationTime >= 500) // Adjust this threshold if needed
    {
        _animationTime = 0;
        _animationIndex = _animationIndex % 3;
    }
    Render();
}

void Character::Render()
{
    // Render character based on animation index
    CustomConsole.GotoXY(_x * 2, _y);
    switch (_animationIndex)
    {
    case 0:
        cout << " M ";
        CustomConsole.GotoXY(_x * 2, _y + 1);
        cout << "/|\\";
        CustomConsole.GotoXY(_x * 2, _y + 2);
        cout << "| |";
        break;
    case 1:
        cout << " M ";
        CustomConsole.GotoXY(_x * 2, _y + 1);
        cout << "/|\\";
        CustomConsole.GotoXY(_x * 2, _y + 2);
        cout << "| |";
        break;
    case 2:
        cout << " M ";
        CustomConsole.GotoXY(_x * 2, _y + 1);
        cout << "/|\\";
        CustomConsole.GotoXY(_x * 2, _y + 2);
        cout << "| |";
        break;
    }
}

void Character::Jump()
{
    if (!_isJumping)
    {
        _isJumping = true;
        _isAir = true;
        _jumpTimer = 0;
    }
}
void Character::Move(int x)
{
    Erase();
    _x += x;
    if (_x < 1)
    {
        _x = 1;
    }
    else if (_x > 23)
    {
        _x = 23;
    }
}

void Character::Erase()
{
    CustomConsole.ClearArea(_x * 2, _y, (_x + 2) * 2, _y + 2);
}

void Character::Release()
{
}
