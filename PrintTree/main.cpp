/*#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

struct Node
{
	int Value;
	Node * Left;
	Node * Right;
	Node(int value):
		Value(value),
		Left(nullptr),
		Right(nullptr)		
		{ }
	~Node() 
	{ 
		if (Left != nullptr)
		{
			delete Left;
			Left = nullptr;
		}
		if (Right != nullptr)
		{
			delete Right;
			Right = nullptr;
		}
	}	
};

void PrintTree(Node * head);
Node * CreateTree(int number);

int main()
{
	Node * tree;
	for(int i = 0; i < 7; ++ i)
	{
		tree = CreateTree(i);
		std::cout << "* Tree " << i << " *******" << std::endl;
		PrintTree(tree);
		std::cout << "****************" << std::endl;
		delete tree;
		tree = nullptr;
	}
	system("pause");
}

void PrintTree(Node * head)
{
	std::vector<Node *> currentLevel, nextLevel;
	currentLevel.push_back(head);
	
	for (int level = 0; level < 6; ++level)
	{		
		bool exit = true;
		int amountNodes = currentLevel.size();
		const float width = 80.0;
		int distance = width / amountNodes;

		// Print vertical lines at the top of nodes
		if (level > 0)
		{
			for(int i = 0; i < amountNodes; ++i)
			{
				std::string text = currentLevel[i] == nullptr ? "" : "|";
				int paddingRight = (distance - text.length()) / 2;
				std::cout << std::setw (distance - paddingRight) << text << std::string( paddingRight, ' ' );
			}
			std::cout << std::endl;
		}

		// Print nodes
		for(int i = 0; i < amountNodes; ++i)
		{
			std::string text = currentLevel[i] == nullptr ? "" : std::to_string(currentLevel[i]->Value);
			int paddingRight = (distance - text.length()) / 2;
			std::cout << std::setw (distance - paddingRight) << text << std::string( paddingRight, ' ' );
			if (currentLevel[i] == nullptr)
			{
				nextLevel.push_back(nullptr);
				nextLevel.push_back(nullptr);
			}
			else
			{				
				nextLevel.push_back(currentLevel[i]->Left);
				nextLevel.push_back(currentLevel[i]->Right);
				if (exit)
				{
					exit = false;
				}
			}
		}
		std::cout << std::endl;

		// Print vertical lines at the bottom of nodes, and horisontal lines
		for(int i = 0; i < amountNodes; ++i)
		{
			std::string text = 
				(currentLevel[i] == nullptr ||
				currentLevel[i]->Left == nullptr &&
				currentLevel[i]->Right == nullptr)
				? " " 
				: "|";
			int center = distance / 2;
			int quarter = center / 2;
			
			std::cout << std::string(quarter , ' ');
			char padChar = '_';
			if (currentLevel[i] == nullptr || currentLevel[i]->Left == nullptr)
			{
				padChar = ' ';
			}
			std::cout << std::string( center - quarter, padChar) << text;
			padChar = '_';
			if (currentLevel[i] == nullptr || currentLevel[i]->Right == nullptr)
			{
				padChar = ' ';
			}
			std::cout << std::string( center - 1 - quarter, padChar);
			std::cout << std::string(quarter , ' ');
		}
		
		std::cout << std::endl;
		
		if (exit)
		{
			break;
		}
		
		currentLevel.clear();
		currentLevel.swap(nextLevel);
		
	}		
}

Node * CreateTree(int number)
{
	Node * result;
	switch(number)
	{
		case 0:
			result = nullptr;
			break;
		case 1:
			result = new Node(1);
			break;
		case 2:
			result = new Node(1);
			result->Left = new Node(12);
			break;
		case 3:
			result = new Node(1);
			result->Left = new Node(12);
			result->Right = new Node(13);
			break;
		case 4:
			result = new Node(1);
			result->Left = new Node(12);
			result->Right = new Node(13);
			result->Right->Left = CreateTree(3);
			result->Right->Right = CreateTree(3);
			break;
		case 5:
			result = new Node(1);
			result->Left = new Node(12);
			result->Right = new Node(13);
			result->Left->Left = CreateTree(3);
			result->Left->Right = CreateTree(3);
			result->Right->Left = CreateTree(3);
			result->Right->Right = CreateTree(3);
			break;
		case 6:
			result = new Node(1);
			result->Left = CreateTree(5);
			result->Right = CreateTree(5);
			break;
		
		default:
			result = nullptr;
	}
	return result;
}
*/


/*
* Tree 0 *******




****************
* Tree 1 *******
                                        1









****************
* Tree 2 *******
                                        1

                    ___________________|

                    |

                   12









****************
* Tree 3 *******
                                        1

                    ___________________|____________________

                    |                                       |

                   12                                      13









****************
* Tree 4 *******
                                        1

                    ___________________|____________________

                    |                                       |

                   12                                      13

                                                  _________|__________

                                                  |                   |

                                                  1                   1

                                             ____|_____          ____|_____

                                             |         |         |         |

                                            12        13        12        13








****************
* Tree 5 *******
                                        1

                    ___________________|____________________

                    |                                       |

                   12                                      13

          _________|__________                    _________|__________

          |                   |                   |                   |

          1                   1                   1                   1

     ____|_____          ____|_____          ____|_____          ____|_____

     |         |         |         |         |         |         |         |

    12        13        12        13        12        13        12        13








****************
* Tree 6 *******
                                        1

                    ___________________|____________________

                    |                                       |

                    1                                       1

          _________|__________                    _________|__________

          |                   |                   |                   |

         12                  13                  12                  13

     ____|_____          ____|_____          ____|_____          ____|_____

     |         |         |         |         |         |         |         |

     1         1         1         1         1         1         1         1

  __|___    __|___    __|___    __|___    __|___    __|___    __|___    __|___

  |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |

  12   13   12   13   12   13   12   13   12   13   12   13   12   13   12   13





****************
Для продолжения нажмите любую клавишу . . .


*/