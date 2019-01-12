#include<iostream>
using namespace std;
class BookShop
    {
    public:
        string bookshop_url,bookshop_name,bookshop_address;
        string title,writer_name,category;
        int price,quantity,edition_number;
        BookShop(){}
        BookShop(string bookshop_url,string bookshop_name,string bookshop_address){
            this->bookshop_url=bookshop_url;
            this->bookshop_name=bookshop_name;
            this->bookshop_address=bookshop_address;
        }

        BookShop(string a,string b,int c,int d,int e,string f){
            title=a;
            writer_name=b;
            price=c;
            quantity=d;
            edition_number=e;
            category=f;
        }
    friend void add_book();
    void bookShop_display()
        {
        cout<<"BookShop Information: "<<endl;
        cout<<"------------------------"<<endl;
        cout<<"URL:"<<bookshop_url<<endl;
        cout<<"Name:"<<bookshop_name<<endl;
        cout<<"Address:"<<bookshop_address<<endl<<endl;
        }
    };

class ShopKeeper
    {
    public:
        string type,title,writer_name,category;
        int price,quantity,edition_number;
    void Book_display()
        {
        cout<<"Customer Book Details: "<<endl;
        cout<<"----------------"<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Writer Name: "<<writer_name<<endl;
        cout<<"Quantity: "<<quantity<<endl;
        cout<<"Edition Number: "<<edition_number<<endl;
        }

    };
    void add_book(BookShop c){
        cout<<"Book Information: "<<endl;
        cout<<"-------------­---"<<endl;
        cout<<"Title: "<<c.title<<endl;
        cout<<"Writer Name: "<<c.writer_name<<endl;
        cout<<"Price: "<<c.price<<endl;
        cout<<"Quantity: "<<c.quantity<<endl;
        cout<<"Edition Number: "<<c.edition_number<<endl;

        }
    class Person
        {
        public:
        string name;
        Person() {}
        };
    class Customer:public Person
        {
        public:
        string type,title,writer_name,category;
        int price,quantity,edition_number;
        Customer(){}
        Customer(string name,string type,string title,string writer_name,int quantity,int edition_number){
        this->name=name;
        this->type=type;
        this->title=title;
        this->writer_name=writer_name;
        this->quantity=quantity;
        this->edition_number=edition_number;
        this->category=category;
        }
        void customer_Book_display()
            {
            cout<<"Customer Book Details: "<<endl;
            cout<<"----------------"<<endl;
            cout<<"Title: "<<title<<endl;
            cout<<"Writer Name: "<<writer_name<<endl;
            cout<<"Quantity: "<<quantity<<endl;
            cout<<"Edition Number: "<<edition_number<<endl;
            }
            };

    class Price
        {
        public:
            friend void Count_price(BookShop b,Customer c);
            };
            void Count_price(BookShop b,Customer c)
            {
            double discount;
            if(b.title==c.title && b.writer_name==c.writer_name && c.type=="Regular" && b.quantity>=c.quantity){
            discount=(b.price*10)/100;
            b.price=b.price-discount;
            cout<<"Mr./Mrs. "<<c.name<<" is a "<<c.type<<" Customer,he/she will get 10% discount,so his/her Discount price:"<<b.price<<" taka."<<endl<<endl;
            }
            else if(b.title==c.title && b.writer_name==c.writer_name && c.type=="NonRegular" && b.quantity>=c.quantity)
            {
            cout<<"Mr./Mrs. "<<c.name<<" is a "<<c.type<<" Customer,he/she will not get 10% discount,so his/her price:"<<b.price<<" taka."<<endl<<endl;
            }
            else{
            cout<<"The book is out of stock."<<endl;
            }
            b.quantity=b.quantity-c.quantity;
            }
    int main()
        {
        BookShop bk1("https://www.boscop.com","Boi Bitan","Kotbari,Cumilla");
        ShopKeeper kobir;
        BookShop b1("Da Vinchi Code","Dawn Brown",180,4,5,"Fiction");
        BookShop b2("UNDER THE VOLCANO","Malcolm Lowry",320,7,7,"NonFiction");

        Person p;
        bk1.bookShop_display();

        Customer c1("Provati","Regular","Da Vinchi Code","Dawn Brown",2,5);
        c1.customer_Book_display();
        Count_price(b1,c1);

        Customer c2("Talash","NonRegular","UNDER THE VOLCANO","Malcolm Lowry",1,5);
        c2.customer_Book_display();
        Count_price(b2,c2);


        }
