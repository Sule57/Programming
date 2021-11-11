#include <iostream>
#include <string.h>     //Enables usage of strings
#include <vector>       //Enables usage of vectors
#include <fstream>      //Enables usage of ifstream and ofstream
using namespace std;    //So we dont have to write every command as std::cout << ...

// Creates a new Class that will be holding the articles and all of their specifications

class Article {
    private:                                                                //Introduces private variables into the class
        int numberOfArticel;
        string description;
        double costPrice;
        int orderDuration;
    public:                                                                 //Introduces public functions into the class
        void setNumberOfArticel (int a) {                                   //(All functions below are just getters and setters to set the specs of an object inside the Article class)
            numberOfArticel = a;
        }
        int getNumberOfArticel () {
            return numberOfArticel;
        }   
        void setDescription (string a) {
            description = a;
        }
        string getDescription () {
            return description;
        }    
        void setCostPrice (float a) {
            costPrice = a;
        }
        float getCostPrice () {
            return costPrice;
        }   
        void setOrderDuration (int a) {
            orderDuration = a;
        }
        int getOrderDuration () {
            return orderDuration;
        } 
};

//Creates a class Stock that will hold all stock related specifications of an Article

class Stock {
    private:                                                                //Introduces private variables into the class
        int articleNumber;
        int actualStock;
        int maximumStock;
        int consumption;
    public:                                                                 //Introduces public functions into the class
        void setArticleNumber (int a) {                                     //(All functions below are just getters and setters to set the specs of an object inside the Stock class)
            articleNumber = a;
        }
        int getArticleNumber () {
            return articleNumber;
        }

        void setActualStock (int a) {
            actualStock = a;
        }
        int getActualStock () {
            return actualStock;
        }
        void setMaximumStock (int a) {
            maximumStock = a;
        }
        int getMaximumStock () {
            return maximumStock;
        }
        void setConsumption (int a) {
            consumption = a;
        }
        int getConsumption () {
            return consumption;
        }
        
};

//Initializes the table into the two vectors holding articles and stocks objects

void initializeTable(vector < Article > &articles, vector < Stock > &stocks) {
    string line;
    int linePos;
    Article a;
    Stock b;

    //Sets up the table file

    string tableFile = "table.txt";

    //Starts ifstream on that file, ifstream is used in order to read files

    ifstream table;

    //Opens the table file

    table.open(tableFile);

    //If the table isn't open throw an error if it's open it runs the code below

    if(!table) { cout << "Unable to open file..."; exit(1);}

    //Gets a full line as a string from the table.txt file

    getline(table, line);

    //While there's lines to read it runs this code on all of them (The code is just reading the information and setting it into an object and then...
    //...pushing that object back into the vector for every line, so that you create a fully described object and at the end you have the vectors full of information on every object (every line)

    while (getline(table, line)){
        linePos = line.find(" | ");
        a.setNumberOfArticel(stoi(line.substr(0, linePos)));
        b.setArticleNumber(a.getNumberOfArticel());
        line.erase(0, linePos + 2);


        linePos = line.find(" | ");
        a.setDescription(line.substr(0, linePos));
        line.erase(0, linePos + 2);


        linePos = line.find(" | ");
        b.setActualStock(stoi(line.substr(0, linePos)));
        line.erase(0, linePos + 2);


        linePos = line.find(" | ");
        b.setMaximumStock(stoi(line.substr(0, linePos)));
        line.erase(0, linePos + 2);


        linePos = line.find(" | ");
        for (int i = 0; i < linePos; i++) {
            if (line[i] == ',') line[i] = '.';
        }
        a.setCostPrice(stof(line.substr(0, linePos)));
        line.erase(0, linePos + 2);


        linePos = line.find(" | ");
        b.setConsumption(stoi(line.substr(0, linePos)));
        line.erase(0, linePos + 2);


        a.setOrderDuration(stoi(line));
        articles.push_back(a);
        stocks.push_back(b);
    }
}

//Calculates the stock value using the formula given in the task sheet from the vectors information and returns it, it's not printed because we print it later on in the txt file

float getStockValue (vector < Article > &a, vector < Stock > &b) {
    float stockValue = 0;
    for (int i = 0; i < a.size(); i++) {
        stockValue = stockValue + b[i].getActualStock() * a[i].getCostPrice();
    }
    return stockValue;
}

//Writes a file called Stock.txt which includes all the information the table.txt file had and the 2 new columns called Reorder Point and Order Proposal, also returns under the table the total stock value

void writeStock (vector < Article > &a, vector < Stock > &b) {

    //ofstream is used to write files, the txt in the brackets is the name of the file and "file1" is how we refer to it in the rest of the code

    ofstream file1("Stocks.txt");
    int reorderPoint, orderProposal;

    //In order to write in our newly created file we use the command previously created file1 the same way we would use the command cout (fairly simple I know)

    file1 <<"No | Description | Actual Stock | Maximum Stock | Cost Price | Consumption per Day | Order Duration | Reorder Point | Order Proposal" << endl;

    //The for loop just prints out the information stated above in the same order as stated above separated by " | "

    for (int i = 0; i < a.size(); i++) {
        reorderPoint = (a[i].getOrderDuration() * b[i].getConsumption() + 2);
        if (b[i].getActualStock() <= reorderPoint) 
            orderProposal = reorderPoint - b[i].getActualStock();
        else 
            orderProposal = 0;

        file1 << a[i].getNumberOfArticel() << " | " << a[i].getDescription() << " | " << b[i].getActualStock() << " | " << b[i].getMaximumStock() << " | " << a[i].getCostPrice() << " € | " << b[i].getConsumption() << " | " << a[i].getOrderDuration() << " | "<< reorderPoint << " | " << orderProposal << endl;
    }

    //This is my little addition, doesn't say it in the task, but I also print out the total stock value in the Stock.txt file (makes sense I know)

    file1 << endl <<  "The stock value is: " << getStockValue(a,b) << " €";
}

//TESTING ENVIRONMENT//

//creates the two vectors to hold the information and runs the two functions we have previously created

int main() {
    vector < Article > articles;
    vector < Stock > stocks;
    initializeTable(articles, stocks);
    writeStock(articles, stocks);
}