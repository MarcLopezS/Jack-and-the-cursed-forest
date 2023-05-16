#include <iostream>
#include "Player.h"


Player::Player()
{
	health_points = 25;
}

Player::~Player()
{
}

void Player::Go(const std::vector<std::string>& userInput)
{

}
void Player::Look(const std::vector<std::string>& userInput) const
{
}

void Player::Take(const std::vector<std::string>& userInput)
{
}

void Player::Drop(const std::vector<std::string>& userInput)
{
}


void Player::Inventory() const
{
}

void Player::Equip(const std::vector<std::string>& userInput)
{
}

void Player::UnEquip(const std::vector<std::string>& userInput)
{
}

void Player::Examine(const std::vector<std::string>& userInput) const
{
}

void Player::Attack(const std::vector<std::string>& userInput)
{
}

void Player::Loot(const std::vector<std::string>& userInput)
{
}

void Player::Exit(const std::vector<std::string>& userInput)
{
}