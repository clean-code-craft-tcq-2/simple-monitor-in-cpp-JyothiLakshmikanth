#include <assert.h>
#include <iostream>
using namespace std;

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  if(temperature < 0 || temperature > 45) {
    cout << "Temperature out of range!\n";
    return false;
  } else if(soc < 20 || soc > 80) {
    cout << "State of Charge out of range!\n";
    return false;
  } else if(chargeRate > 0.8) {
    cout << "Charge Rate out of range!\n";
    return false;
  }
  return true;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
// void main(){
// Array of String
// string[]  names={"abc",xyz","pqrs"};
// 1.iterate
// foreach name in names
//    2.Predicate
//         if(sizeOf(name) > 3)
//            3. Print name
// }
 
// string iterate(array){}
// bool Predicate(string){}
// void print(string){}
 
// iterate(Array names).predicate(string print).print(string item)
// //unix commands 
//   c1|c2|C3
// V1
// ----------------------------------------------------------
// <Array of String> Query(Array of String){
//   ResutArray selectedStringItems;
//   foreach item in array
//        2.Predicate
//         if(sizeOf(name) > 3)
//            3.Add item -> selectedStrngItems

//   return selectedStringItems;
// }
// -------------------------------------------------------------
// v2
// ------------------------------------------------------------
// bool isStringLengthGreaterThanThree(string item){
//    return item length > 3;
// }
 
// <Array of String> Query(Array of String, prdicateFunction predicate){
//   ResutArray selectedStringItems;
//   foreach item in array
//        2.Predicate
//         if(predicate(item))
//            3.Add item -> selectedStrngItems

//   return selectedStringItems;
// }
// -----------------------------------------------------------------
 
// void Print(string item){
//   print(item);//IOStream
// }
// -----------------------------------------------------------------
 
// void main(){
// string[]  names={"abc",xyz","pqrs"};
// resultArray=Query(names,&isStringLengthGreaterThanThree);
// //iterate 
// /*for(int i=0;i<=array length;i++){
//   printf("%s",array[i]);
// }*/
 
// Iterate(array,&Print);
 
// }
 
// void IterateString(array,funPointer){
//   for i=0 i< array length ; i++{
//    fun(array[i]);
//   }
// }
 

// Iterate<string>(arrayOFString, &Print);
// Iterate<int>(arrayOfInt,&Print)
 

// //pure function
// int add(int x,int y){
//     return x+y;
// }
 
// int addProxy(int x,int y){
//     //Cheack Arguments
//     //Check Cache
//     //update Cache
//     //return resut from (cache,add)
// }
// int result=addProxy(10,20);
// Cache -Result
// add(10,20);
// add(10,20);
// application of map -> yet to do
// #include<iostream>
// #include<string>
// #include<list>
// #include<map>
// using namespace std;

// 	class Book
// 	{
// 	private:
// 		string bookTitle;
// 		double bookCost;

// 	public:
// 		Book(string title,double cost):bookTitle(title),bookCost(cost)
// 		{
// 		}
// 		virtual ~Book()
// 		{
// 		}
// 		string getBookTitle()const
// 		{
// 			return bookTitle;
// 		}

// 		double getBookCost()const
// 		{
// 			return bookCost;
// 		}

		
// 	};
// 	class TechnicalBook : public Book
// 	{
// 	private:
// 		static double rateOfDisc;
// 	public:
// 		TechnicalBook(string title,double cost):Book(title,cost)
// 		{}
// 		double getRateOfDisc()
// 		{
// 			return rateOfDisc;
// 		}
// 	};

// 	double TechnicalBook::rateOfDisc=0.05;

// 	class ManagementBook : public Book
// 	{
// 		private:
// 		static double rateOfDisc;
// 		public:
// 		ManagementBook(string title,double cost):Book(title,cost)
// 		{}
// 		double getRateOfDisc()
// 		{
// 			return rateOfDisc;
// 		}
// 	};
// 	double ManagementBook::rateOfDisc=0.10;


// 	class BookDetailed
// 	{
// 	private:
// 		Book *b;
// 		int bookStock;
// 	public:
// 		BookDetailed(string bookTitle , double bookCost , int bookStock,int choice):b(NULL),bookStock(bookStock)
// 		{
			
// 			if(choice==1)
// 				b=new TechnicalBook(bookTitle,bookCost);
// 			else if(choice==2)
// 				b=new ManagementBook(bookTitle,bookCost);
			
// 		}

// 		~BookDetailed()
// 		{
// 			if(b!=NULL)
// 				delete b;
// 		}
// 		Book* getBook()
// 		{
// 			return b;
// 		}

// 		int getBookStock()const
// 		{
// 			return bookStock;
// 		}

// 		void setBookStock(int updatedstock)
// 		{
// 			bookStock=updatedstock;
// 		}
// 	};

// 	class BookStore
// 	{
// 	string BookStoreName;
// 	map<string,list<BookDetailed *>> bm;
	
// 	BookStore():BookStoreName("Gangarams")
// 	{
		
// 	}
// 	static BookStore *bs;
// public:

// 	static BookStore* CreateInstance()
// 	{
// 		if(bs==NULL)
// 			bs=new BookStore();
// 		return bs;
// 	}

// 	static void DeleteInstance()
// 	{
// 		if(bs)
// 			delete bs;
// 	}


// 	 void AddBook()
// 	{
// 			string title;
// 			double cost;
// 			int stock;
// 			int status=false;
// 			int choice=0;
// 			list<BookDetailed*>l;
// 			list<BookDetailed*>::iterator lt;
// 			map<string,list<BookDetailed*>>::iterator mt;
// 			BookDetailed *b=NULL;
// 			Book *bp=NULL;
		    
// 			cout<<"1:Add a TechnicalBook "<<endl;
// 			cout<<"2:Add a Management Book"<<endl;
// 			cout<<"Enter your choice"<<endl;
// 			cin>>choice;
// 			cout<<"enter the title"<<endl;
// 			cin>>title;
// 			//Check for availability of the book
// 			for(mt=bm.begin();mt!=bm.end();mt++)
// 			{
// 				l = mt->second;
// 				for(lt=l.begin();lt!=l.end();lt++)
// 				{
// 					b=*lt;
// 					if(b->getBook()->getBookTitle()==title)
// 					{
// 						status=true;
// 						break;
// 					}
// 				}
// 				if(status)
// 					break;
// 			}
			
			
// 			if(status)
// 			{
// 				cout<<"book by the title "<<title<<" exists -> existing stock is updated"<<endl;
// 				cout<<"enter the stock "<<endl;
// 				cin>>stock;
// 				int updatedstock = b->getBookStock()+stock;
// 				b->setBookStock(updatedstock);
				
// 			}
// 			else
// 			{
// 				cout<<"book by the title "<<title<< " does not exists -> adding a book to the catalog"<<endl;
// 				cout<<"enter the cost and stock "<<endl;
// 				cin>>cost;
// 				cin>>stock;
// 				b = new BookDetailed(title,cost,stock,choice);

// 				if(choice==1)
// 				{
// 					if(bm.find("TechnicalBook")!=bm.end())
// 					{
// 						list<BookDetailed*> &tList = bm["TechnicalBook"];
// 						tList.push_back(b);
// 					}
// 					else
// 					{
					
// 						list<BookDetailed*> tl;
// 						tl.push_back(b);
// 						bm["TechnicalBook"] = tl;
// 					}
// 				}

// 				if(choice==2)
// 				{
// 					if(bm.find("ManagementBook")!=bm.end())
// 					{
					
// 						list<BookDetailed*> &mList = bm["ManagementBook"];
// 						mList.push_back(b);
// 					}
// 					else
// 					{
					
// 						list<BookDetailed*> ml;
// 						ml.push_back(b);
// 						bm["ManagementBook"] = ml;
// 					}
// 				}
// 				status=true;
				
// 			}

// 		}


// 	 void DispBook()
// 	{
// 		 map<string,list<BookDetailed*>,less<string>>::iterator mt;
// 		 list<BookDetailed*>::iterator lt;
// 		 list<BookDetailed*> l;
// 		 BookDetailed *b=NULL;
// 		 int choice;
// 		 Book *bp=NULL;
		 
// 		 if(bm.size()==0)
// 			 cout<<"Catalog is empty"<<endl;
// 		 else
// 		 {
// 			 cout<<"1:Display All Books"<<endl;
// 			 cout<<"2:Display only Technical Books"<<endl;
// 			 cout<<"3:Display only Management Books"<<endl;
// 			 cout<<"enter your choice"<<endl;
// 			 cin>>choice;

// 			 if(choice==1)
// 			 {
// 			 for(mt=bm.begin();mt!=bm.end();mt++)
// 				{
// 					if(mt->first.size()!=0)
// 					{
// 						cout<<"---------"<<mt->first<<" are: ------------"<<endl;
// 						l = mt->second;
// 						for(lt=l.begin();lt!=l.end();lt++)
// 						{
// 							b=*lt;
// 							cout<<"BookstoreName:"<<BookStoreName<<endl;
// 							cout<<"Title:"<<b->getBook()->getBookTitle()<<endl;
// 							cout<<"Cost:"<<b->getBook()->getBookCost()<<endl;
// 							cout<<"Stock:"<<b->getBookStock()<<endl;
// 							bp = b->getBook();	
// 							if(typeid(*bp)==typeid(TechnicalBook))
// 								cout<<"rateofDisc:"<<((TechnicalBook*)bp)->getRateOfDisc()<<endl;
// 							if(typeid(*bp)==typeid(ManagementBook))
// 								cout<<"rateofDisc:"<<((ManagementBook*)bp)->getRateOfDisc()<<endl;
// 							cout<<"-------------------------------------"<<endl;
								
// 						}
// 					}
// 	    		 }
// 			 }

// 			 else if(choice==2)
// 			 {
// 					if(bm.find("TechnicalBook")==bm.end())
// 						cout<<"TechnicalBook entries are not available in the catalog"<<endl;
// 					else
// 					{
// 						l = bm["TechnicalBook"];
// 						cout<<"---------Technical Books are: ------------"<<endl;
// 						for(lt=l.begin();lt!=l.end();lt++)
// 						{
// 								b=*lt;
// 								bp = b->getBook();
// 								cout<<"BookstoreName:"<<BookStoreName<<endl;
// 								cout<<"Title:"<<bp->getBookTitle()<<endl;
// 								cout<<"Cost:"<<bp->getBookCost()<<endl;
// 								cout<<"Stock:"<<b->getBookStock()<<endl;
// 								cout<<"rateofDisc:"<<((TechnicalBook*)bp)->getRateOfDisc()<<endl;	
// 								cout<<"-------------------------------------"<<endl;
// 						}
// 					}
// 			 }

// 			 else if(choice==3)
// 			 {
// 				 if(bm.find("ManagementBook")==bm.end())
// 						cout<<"ManagementBook entries are not available in the catalog"<<endl;
// 				 else
// 				 {
// 					l = bm["ManagementBook"];
// 					cout<<"---------Management Books are: ------------"<<endl;
// 					for(lt=l.begin();lt!=l.end();lt++)
// 					{
// 							b=*lt;
// 							bp = b->getBook();
// 							cout<<"BookstoreName:"<<BookStoreName<<endl;
// 							cout<<"Title:"<<bp->getBookTitle()<<endl;
// 							cout<<"Cost:"<<bp->getBookCost()<<endl;
// 							cout<<"Stock:"<<b->getBookStock()<<endl;
// 							cout<<"rateofDisc:"<<((ManagementBook*)bp)->getRateOfDisc()<<endl;		
// 							cout<<"-------------------------------------"<<endl;
// 					}
// 				}
// 			 }
// 		 }
// 	 }
	
	
// 	~BookStore()
// 	{
// 		map<string,list<BookDetailed*>,less<string>>::iterator mt;
// 		list<BookDetailed*>::iterator t1,t2;
// 		BookDetailed *bp=NULL;
// 		if(bm.size()!=0)
// 		{
// 			for(mt=bm.begin();mt!=bm.end();mt++)
// 			{
// 				list<BookDetailed*> &bl = mt->second;
// 				if(bl.size()!=0)
// 				{
// 					for(t1=bl.begin();t1 != bl.end();)
// 					 {
// 						  bp = (*t1);
// 						  t2 = t1;
// 						  t1++;
// 						  delete (bp);
// 						  bl.remove(bp);
					  
// 					 }
// 				}

// 			}
// 		}
// 	}
	

// 	 void SearchBook()
// 	{
// 		string title;
// 		int stock;
// 		BookDetailed *b=NULL;
// 		Book *bp=NULL;
// 		map<string,list<BookDetailed*>,less<string>>::iterator mt;
// 		list<BookDetailed*>::iterator lt;
		

// 		if(bm.size()==0)
// 			cout<<"Catalog is empty"<<endl;
// 		else
// 		{
// 			cout<<"enter the required title and stock"<<endl;
// 			cin>>title>>stock;

// 			char ch;
// 			double rateofdisc,cost;
// 			bool status=false;
// 			for(mt=bm.begin();mt!=bm.end();mt++)
// 			{
// 				list<BookDetailed*> &bl = mt->second;
// 				for(lt=bl.begin();lt!=bl.end();lt++)
// 				{
// 					b=*lt;
// 					bp = b->getBook();
// 					if(bp->getBookTitle()==title)
// 						{
// 							status=true;
// 							if(stock<=b->getBookStock())
// 							{
// 								cout<<"Book available with sufficient stock"<<endl;

// 								if(typeid(*bp)==typeid(class TechnicalBook))
// 									rateofdisc =((TechnicalBook*)bp)->getRateOfDisc();
// 								if(typeid(*bp)==typeid(ManagementBook))
// 									rateofdisc =((ManagementBook*)bp)->getRateOfDisc();
								
// 								cout<<"Billing Cost before Discount:"<<(bp->getBookCost()*stock)<<endl;
// 								cost = (bp->getBookCost()*stock);
// 								cost = cost - (rateofdisc*cost);
// 								cout<<"Billing Cost After Discount:"<<cost<<endl;
// 								cout<<"enter y to purchase"<<endl;
// 								cin>>ch;
// 								if(ch=='y')
// 								{
// 									int availablestock = b->getBookStock()-stock;
// 									b->setBookStock(availablestock);
// 									if(b->getBookStock()==0)
// 									{
// 										delete b;
// 										bl.remove(b);
// 										break;
// 									}
// 								}
								
// 							}
// 							else
// 							{
// 								cout<<"Book available but stock is insufficient"<<endl;
// 								break;
// 							}
// 						}
// 					}
// 				}
				
// 				if(status==false)
// 					cout<<"book not available"<<endl;
// 			}
// 	}
// };



// BookStore* BookStore::bs=NULL;

// int main()
// {
	
// 	int choice;
// 	BookStore *bs = BookStore::CreateInstance();
	
// 	do
// 	{
// 		cout<<"1:addBook 2:dispBook 3:searchBook"<<endl;
// 		cout<<"enter your choice"<<endl;
// 		cin>>choice;
// 		switch(choice)
// 		{
// 		case 1:
// 			bs->AddBook();
// 			break;

// 		case 2:
// 			bs->DispBook();
// 			break;

// 		case 3:
// 			bs->SearchBook();
// 			break;

// 		default:
// 			cout<<"invalid choice"<<endl;
// 			break;
// 		}
// 		cout<<"enter 1 to continue"<<endl;
// 		cin>>choice;
// 	}while(choice==1);

// 	BookStore::DeleteInstance();
// }


