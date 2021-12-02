#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
using namespace std;

/**
 * @brief Starting the class Article that will hold all articles and their values as objects (Also includes getters and setters)
 */

class Article {
    private:
        int numberOfArticel;
        string description;
        double costPrice;
        int orderDuration;
    public:
        void setNumberOfArticel (int a) {
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

/**
 * @brief Starting the class Stock that will hold the stock, all articles inside of it and the values of the stock connected to a certain article
 */

class Stock {
    private:
        int articleNumber;
        int actualStock;
        int maximumStock;
        int consumption;
    public:
        void setArticleNumber (int a) {
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

/**
 * @brief Initializes the table from the table.txt file and pushes them into the vectors that hold objects of type Article and Stock
 * 
 * @param articles A vector holding all articles
 * @param stocks A vector holding all stock characteristics of an article
 */

void initializeTable(vector < Article > &articles, vector < Stock > &stocks) {
    string line;
    int linePos;
    Article a;
    Stock b;
    string tableFile = "table.txt";
    ifstream table;
    table.open(tableFile);
    if(!table) { cout << "Unable to open file..."; exit(1);}
    getline(table, line);
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

/**
 * @brief Get the Stock Value object
 * 
 * @param a References the Vector holding Articles
 * @param b References the Vector holding stock characteristics of an Article
 * @return the complete value of the stock in €, written out in the Stock.txt file
 */

float getStockValue (vector < Article > &a, vector < Stock > &b) {
    float stockValue = 0;
    for (int i = 0; i < a.size(); i++) {
        stockValue = stockValue + b[i].getActualStock() * a[i].getCostPrice();
    }
    return stockValue;
}

/**
 * @brief Writes the Stock.txt file to the home directory of the project, it includes all files that were previously availavble in the table.txt file
 * but also includes new information like the Reorder Point, the Order Proposal and the Stock Value 
 * 
 * @param a References the Vector holding Articles
 * @param b References the Vector holding stock characteristics of an Article
 */

void writeStock (vector < Article > &a, vector < Stock > &b) {
    ofstream file1("Stocks.txt");
    int reorderPoint, orderProposal;
    file1 <<"No | Description | Actual Stock | Maximum Stock | Cost Price | Consumption per Day | Order Duration | Reorder Point | Order Proposal" << endl;
    for (int i = 0; i < a.size(); i++) {
        reorderPoint = (a[i].getOrderDuration() * b[i].getConsumption() + 2);
        if (b[i].getActualStock() <= reorderPoint) 
            orderProposal = reorderPoint - b[i].getActualStock();
        else 
            orderProposal = 0;
        file1 << a[i].getNumberOfArticel() << " | " << a[i].getDescription() << " | " << b[i].getActualStock() << " | " << b[i].getMaximumStock() << " | " << a[i].getCostPrice() << " € | " << b[i].getConsumption() << " | " << a[i].getOrderDuration() << " | "<< reorderPoint << " | " << orderProposal << endl;
    }
    file1 << endl <<  "The stock value is: " << getStockValue(a,b) << " €";
}

/**
 * @brief Testing area, Creates the two Vectors that will hold Articles and its Stock characteristics and calls the functions that will
 * initialize the table into Vectors and write a new Stock.txt file.
 */

int main() {
    vector < Article > articles;
    vector < Stock > stocks;
    initializeTable(articles, stocks);
    writeStock(articles, stocks);
}