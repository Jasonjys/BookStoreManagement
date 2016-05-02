#include <iostream>
#include <string>
#include <sstream>
#include "BMScontrol.h"

using namespace std;

BMScontrol::BMScontrol()
{
	view = new UImanager();
	user = new User();
	courses = new Dlist<Course*>();
	size = 0;
}

BMScontrol::~BMScontrol()
{
	delete view;
	courses->cleanUp();
	delete courses;
	this->cleanUp();
	delete user;
}

void BMScontrol::launch()
{
	int    choice;
	string code;

	while (1) 
	{
		choice = -1;
		view->mainMenu(&choice);
		if (choice == 0)
			break;
		else if (choice == 1) 
		{
			while(1)
			{
				view->subMenuAdd(&choice);
				if(choice == 0) break;
				else if(choice == 1)
				{
					Course *newCourse;
					view->getCourseData(&newCourse);
					*courses += newCourse;
					view->cAddedMessage();
					break;
				}
				else if(choice == 2)
				{
					int num = 0;
					if(view->getNumCourse(num))
					{
						Dlist<Course*>* newList = new Dlist<Course*>();
						for(int i = 0; i < num; i++)
						{
							Course *newCourse;
							view->getCourseData(&newCourse);
							*newList += newCourse;
							view->cAddedMessage();
						}
						*courses += *newList;
						delete newList;
						break;
					}
					else break;
				}
				view->pause();
			}
		}
		else if (choice == 2) 
		{
			while(1)
			{
				view->subMenuRemove(&choice);
				if(choice == 0) break;
				else if(choice == 1)
				{
					Course* toRemove;
					string input = view->getCourseCode();

					if(checkCourse(input, &toRemove))
					{
						for(int i = 0; i < toRemove->getNumBooks(); i++)
						{
							Product* theBook = toRemove->getBookArray()->getBook(i);
							deleteProduct(theBook);
						}

						*courses -= toRemove;
						view->cDeletedMessage();
					}
					else
					{
						view->cNotExist();
					}
					break;
				}
				else if(choice == 2)
				{
					int num = 0;
					if(view->getNumCourse(num))
					{
						Dlist<Course*>* newList = new Dlist<Course*>();
						for(int i = 0; i < num; i++)
						{
							Course* toRemove;
							string input = view->getCourseCode();
							if(checkCourse(input, &toRemove))
							{
								for(int i = 0; i < toRemove->getNumBooks(); i++)
								{
									Product* theBook = toRemove->getBookArray()->getBook(i);
									deleteProduct(theBook);
								}
								*newList += toRemove;
								view->cDeletedMessage();
							}
							else
							{
								view->cNotExist();
								break;
							}
						}
						*courses -= *newList;
						delete newList;
						break;
					}
					else break;

				}
				view->pause();
			}
		}
		else if (choice == 3) 
		{
			view->printCourses(courses);
		}
		else if (choice == 4) 
		{
			Course* toAddBook;
			string input = view->getCourseCode();
			if(checkCourse(input, &toAddBook))
			{
				Book *newBook;
				view->getBookData(&newBook);
				//courses->getCourse(i)->addBook(newBook);
				toAddBook->addBook(newBook);

				Product* product = newBook;

				addProduct(product);
			}
			else
			{
				view->cNotExist();
			}
		}
		else if(choice == 5)
		{
			Course* toList;
			string input = view->getCourseCode();
			if(checkCourse(input, &toList))
			{
				view->listBooks(toList);
			}
			else
			{
				view->cNotExist();
			}
		}
		else if(choice == 6)
		{
			choice = -1;
			while(1)
			{
				view->subMenuProduct(&choice);
				if(choice == 0) break;
				else if(choice == 1)
				{
					Book* newBook;
					view->getBookData(&newBook);
					Product* newProduct = newBook;
					addProduct(newProduct);
					//delete products[0];
					break;
				}
				else if(choice == 2)
				{
					Laptop* newLaptop;
					view->getLaptopData(&newLaptop);
					Product* newProduct = newLaptop;
					addProduct(newProduct);
					break;
				}
				else if(choice == 3)
				{
					Eraser* newEraser;
					view->getEraserData(&newEraser);
					Product* newProduct = newEraser;
					addProduct(newProduct);
					break;
				}
				else if(choice == 4)
				{
					Pencil* newPencil;
					view->getPencilData(&newPencil);
					Product* newProduct = newPencil;
					addProduct(newProduct);
					break;
				}
			}
		}
		else if(choice == 7)
		{
			choice = -1;
			while(1)
			{
				choice = -1;
				view->subMenuBuy(&choice);
				string input;
				int index;
				float discountedPrice;
				float total = user->getTotal();

				if(choice == 0) break;
				else if(choice == 1)
				{
					input = view->getString("title", "book");
					if(user->buy(products, size, input, index, total, discountedPrice))
					{
						view->purchased(discountedPrice);
						string info = products[index]->generateString();
						view->coutString(info);
						deleteProduct(products[index]);

						if(total >= 100 && total < 300)
						{
							if(user->getMembership() != "Silver")
							{
								user->changeStats();
								view->promoted();
							}
							user->setTotal(total);
						}
						else if (total >= 300)
						{
							if(user->getMembership() != "Gold")
							{
								user->changeStats();
								view->promoted();
							}
							user->setTotal(total);
						}
					}
					else 
					{
						view->purchasedFailed();
					}
				}

				else if(choice == 2)
				{
					input = view->getString("brand", "laptop");
					if(user->buy(products, size, input, index, total, discountedPrice))
					{
						view->purchased(discountedPrice);
						string info = products[index]->generateString();
						view->coutString(info);
						deleteProduct(products[index]);

						if(total >= 100 && total < 300)
						{
							if(user->getMembership() != "Silver")
							{
								user->changeStats();
								view->promoted();
							}
							user->setTotal(total);
						}
						else if (total >= 300)
						{
							if(user->getMembership() != "Gold")
							{
								user->changeStats();
								view->promoted();
							}
							user->setTotal(total);
						}
					}
					else 
					{
						view->purchasedFailed();
					}
				}
				
				else if(choice == 3)
				{
					input = view->getString("brand", "eraser");
					if(user->buy(products, size, input, index, total, discountedPrice))
					{
						view->purchased(discountedPrice);
						string info = products[index]->generateString();
						view->coutString(info);
						deleteProduct(products[index]);

						if(total >= 100 && total < 300)
						{
							if(user->getMembership() != "Silver")
							{
								user->changeStats();
								view->promoted();
							}
							user->setTotal(total);
						}
						else if (total >= 300)
						{
							if(user->getMembership() != "Gold")
							{
								user->changeStats();
								view->promoted();
							}
							user->setTotal(total);
						}
					}
					else 
					{
						view->purchasedFailed();
					}
				}

				else if(choice == 4)
				{
					input = view->getString("brand", "pencil");
					if(user->buy(products, size, input, index, total, discountedPrice))
					{
						view->purchased(discountedPrice);
						string info = products[index]->generateString();
						view->coutString(info);
						deleteProduct(products[index]);

						if(total >= 100 && total < 300)
						{
							if(user->getMembership() != "Silver")
							{
								user->changeStats();
								view->promoted();
							}
							user->setTotal(total);
						}
						else if (total >= 300)
						{
							if(user->getMembership() != "Gold")
							{
								user->changeStats();
								view->promoted();
							}
							user->setTotal(total);
						}
					}
					else 
					{
						view->purchasedFailed();
					}
				}
				view->pause();
			}
		}
		else if(choice == 8)
		{
			string output;
			generateString(output);
			view->coutString(output);
		}
		else if(choice == 9)
		{
			string status = user->membership();
			view->coutString(status);
		}
		view->pause();
	}
}


//This function takes a Product pointer and add it to the array
void BMScontrol::addProduct(Product* product)
{
	if (size == MAX_PRODUCTS)
		return;

	products[size] = product;
	size++;
}

//deleteProduct function remove the product pointers from 
//the array and free that product at that position.
void BMScontrol::deleteProduct(Product* product)
{
	for(int i = 0; i < size; i++)
	{
		if(products[i] == product)
		{
			delete products[i];
			for(int j = i; j < size-1; j++)
			{
				products[j] = products[j+1];
			}
		}
	}
	size--;
}

//This function generate the string of all the base class info
void BMScontrol::generateString(string& output)
{
	if(size == 0)
		output = "\nNo product exist";
	else
		for(int i = 0; i < size; i++)
		{
			string num;
			stringstream xx;
			xx << i+1;
			num = xx.str();

			output += "\nProduct " + num 
					+ "\n" + products[i]->generateString();
		}
}

//the clean up function loops through the product array and 
//free all the memory
void BMScontrol::cleanUp()
{
	for(int i = 0; i < size; i++)
	{
		delete products[i];
	}
}

bool BMScontrol::checkCourse(string& code, Course** output)
{
	for(int i = 0; i < courses->getSize(); i++)
	{
		if(courses->getData(i)->getCode() == code)
		{
			*output = courses->getData(i);
			return true;
		}
	}
	return false;
}