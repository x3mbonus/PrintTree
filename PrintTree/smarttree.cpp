#include <memory>
#include <vector>
#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>

struct Node
{
	int Value;
	std::shared_ptr<Node> Left;
	std::shared_ptr<Node> Right;
	Node (int value) : 
		Value(value)
	{
		//std::cout << "Node (int value)" << std::endl;
	}
	Node (const Node &)
	{
		//std::cout << "Node (const Node &)" << std::endl;
	}
	
	Node (Node &&)
	{
		//std::cout << "Node (Node &&)" << std::endl;
	}
	~Node()
	{
		//std::cout << "~Node()" << std::endl;
	}
};

void PrintTree(std::shared_ptr<Node> head);
std::shared_ptr<Node> CreateTree(int number, int value = 0);
void PrintTreeHorisontal(std::shared_ptr<Node> node, int level = 0);

int main()
{	
	for(int i = 0; i < 7; ++ i)
	{		
		auto tree = CreateTree(i);
		std::cout << std::string(10, '*') << std::setfill('*') << std::left << std::setw(30) << " Tree " + std::to_string(i) << std::setfill(' ') << std::endl;
		PrintTree(tree);
		std::cout << std::string(40, '*') << std::endl << std::endl;
		PrintTreeHorisontal(tree);
		std::cout << std::string(40, '*') << std::endl << std::endl;
	}
	system("pause");
}

void PrintTreeHorisontal(std::shared_ptr<Node> node, int level)
{
	if (node)
	{
		if (node->Right)
		{
			PrintTreeHorisontal(node->Left, level + 1);
		}

		std::cout << std::right << std::setw(3 * (level + 1)) << node->Value << std::endl;

		if (node->Left)
		{
			PrintTreeHorisontal(node->Right, level + 1);
		}
	}
}

void PrintTree(std::shared_ptr<Node> head)
{
	if (!head)
	{
		return;
	}
	std::vector<std::shared_ptr<Node>> currentLevel, nextLevel;
	currentLevel.push_back(head);
	const int width = 80;
	bool exit = false;
	while (!exit)
	{
		int amount = currentLevel.size();
		int distance = width / amount;
		std::string text;
		exit = true;
		for(auto node : currentLevel)
		{
			if (node)
			{
				text = std::to_string(node->Value);
				nextLevel.push_back(node->Left);
				nextLevel.push_back(node->Right);
				if (exit && 
					(node->Left || node->Right))
				{
					exit = false;
				}
			}
			else
			{
				text = "";
				nextLevel.emplace_back(nullptr);
				nextLevel.emplace_back(nullptr);
			}
			int paddingLeft = (distance - text.length())/2;
			int paddingRight = distance - paddingLeft - text.length();
			std::cout << std::string(paddingLeft, ' ') << text << std::string(paddingRight, ' ');
		}
		std::cout << std::endl;
		currentLevel.swap(nextLevel);
		nextLevel.clear();
	}
}



std::shared_ptr<Node> CreateTree(int number, int value)
{
	std::shared_ptr<Node> result(nullptr);
	switch(number)
	{
		case 0:
			result = nullptr;
			break;
		case 1:
			result = std::make_shared<Node>(value);
			break;
		case 2:
			result = CreateTree(1, 1);
			result->Left = CreateTree(1, 12);
			break;
		case 3:
			result = CreateTree(2, 1);
			result->Right = CreateTree(1, 13);
			break;
		case 4:
			result = CreateTree(3);
			result->Right->Left = CreateTree(3);
			result->Right->Right = CreateTree(3);
			break;
		case 5:
			result = CreateTree(4);
			result->Left->Left = CreateTree(3);
			result->Left->Right = CreateTree(3);
			break;
		case 6:
			result = CreateTree(1);
			result->Left = CreateTree(5);
			result->Right = CreateTree(5);
			break;
		
		default:
			result = nullptr;
	}
	return result;
}