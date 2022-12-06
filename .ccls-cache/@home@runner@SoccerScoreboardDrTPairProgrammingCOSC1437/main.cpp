// Sterling Swanson
//1437 - COSC
//Dr_T McMillan

#include <iostream>
#include <string> 
#include <unistd.h>
#include "Input_Validation_Extended.h"
using namespace std; 

class Team 
{
  private:
    int score; 
    bool homeStatus; 
    string name; 
    int shotsOnGoal; 
    string coachName; 
    int TimeOuts;
    string city;
  public:
      Team() //default constructor 
      {
        score = 0; 
        homeStatus = false; //visitor = false, home = true
        name = "Dragons"; 
        shotsOnGoal = 0; 
        coachName = "Default coachName"; 
      }
      void setScore(int s) { score = s; }
      void setHomeStatus(bool hs) { homeStatus = hs; }
      void setName(string n) { name = n; }
      void setShotsOnGoal(int sog) { shotsOnGoal = sog; }
      void setCoachName(string sCN) { coachName = sCN; }
      void setTimeouts(int t) { TimeOuts = t;}
      void setCity(string c) { city = c;}
      int getScore() const { return score; }
      bool getHomeStatus() const { return homeStatus; }
      string getName() const { return name; }
      int getShotsOnGoal() const { return shotsOnGoal; }
      string getCoachName() const { return coachName; }
      int getTimeouts() const { return TimeOuts;}
      string getCity() const {return city;}
};

class Scoreboard
{
  private:
    int half; 
    Team home; //object that is a member of another object
    Team visitor; 
    string city;
  public: 
    Scoreboard()
    {
      half = 0; 
    }  
    void setHalf(int h) { half = h; }
    void setHome(Team hSet) { home = hSet; }
    void setVisitor(Team vSet) { visitor = vSet; }
    int getHalf() const { return half; }
    Team getHome() const { return home; }
    Team getVisitor() const { return visitor; }
    void showScoreboard()
    {
      string color = ""; 
      string reset = "\x1b[0m";
      color = "\x1b[32;4m"; //green 
      string score = "\x1b[36;1m"; //score color 
      cout << color << "FootBall Scoreboard" << reset << endl; 
      cout << home.getName() << "\t\t" << visitor.getName()  << endl; 
      cout << "\t" << score << home.getScore() << reset << "\t\t\t\t\t\t" << visitor.getScore() << reset  <<  endl; 
      cout << score << home.getCoachName() << reset << "\t\t" << visitor.getCoachName() << reset << endl; 
      cout << home.getTimeouts() << reset << "\t\t" << visitor.getTimeouts() << reset << "\t\t"  << endl;
  cout << home.getCity() << reset << "\t\t" << visitor.getCity() << reset << "\t\t" << endl;
      
      for(int i = 0; i < 47; i++) { cout << "*"; } cout << endl;
       
       //proces to show the home team status
       cout << "Home> \t"; 
       if(home.getHomeStatus() == true)
       {
         cout << "Team 1: " << home.getName() << "*"; 
       }
       else if(visitor.getHomeStatus() == true)
       {
         cout << "Team 2: " << visitor.getName() << "*"; 
       }
       else
       {
         cout << "Error: "; 
       }
       
       cout  << endl; 
    }
};

int main() 
{
  Scoreboard s;
  Team tOne;
  Team tTwo; 
  string newName = ""; 
  string userChoice = ""; 
  string newCoachName = ""; 
  int homeTeamQuestion = 0; 
  int newScore = 0; 
  int newOuts = 0;
  string newCity = "";
  string color = ""; 
  string reset = "\x1b[0m";
  //Set the home team 
  tOne.setHomeStatus(true); //tOne is the Home Team now   

  //add some initial data to s
  s.setHome(tOne); 
  s.setVisitor(tTwo); 

  
  //Loop this to make it an interactive menu

  do 
  {
      system("clear"); //clear the screen of previous content 
      s.showScoreboard(); //show the current scoreboard data
      //menu choices 
      cout << "A = Update Home Team Name" << endl; 
      cout << "B = Update Home Team Score" << endl; 
      cout << "C = Update Home Status" << endl; 
      cout << "D = Update Visting Team Coach" << endl; 
      cout << "F = Update vistor Team Name" << endl;
      cout << "L = Update the vistor's city" << endl;
      cout << "M = Update vistor Team Coach" << endl;
      cout << "X = Update Timeout Count" << endl;
      cout << "E = Exit" << endl;
      cout << ">"; 
      cin >> userChoice; 

      if(userChoice == "A" || userChoice == "a")
      {
        //Dr_T challenge Accept a new name for s's home team
        cout << "****Update Home Team Score module*** " << endl; 
        cout << "\nPlease enter a new name for the home team: ";
        cin >> newName; 
        //change that home team's default name
        tOne.setName(newName); //set tOne's data to the new desired name
      }
      else if(userChoice == "B" || userChoice == "b")
      {
        cout << "\nUpdate Home Score Module****" << endl; 
        cout << "\nPlease enter a new score for the home team: "; 
        cin >> newScore; 
        tOne.setScore(newScore);  //set the new score for tOne        
      }
      else if(userChoice == "C" || userChoice == "c")
      {
        cout << "\nUpdate Home Status Module****" << endl; 
        cout << "\nWho is the home team: 1 = T1, 2=T2: "; 
        homeTeamQuestion = validateInt(homeTeamQuestion); 
       // cin >> homeTeamQuestion; 
        if(homeTeamQuestion == 1)
        {
          tOne.setHomeStatus(true); 
          tTwo.setHomeStatus(false); 
        }
        else if(homeTeamQuestion == 2)
        {
          tOne.setHomeStatus(false); 
          tTwo.setHomeStatus(true);
        }
        else
        {
          cout << "\nInvalid Input!" << endl;
          sleep(2); 
        }
      }
      else if(userChoice == "D" || userChoice == "d")
      {
          cout << "\nUpdate Visitor Coach Module****" << endl; 
          cout << "\nPlease enter the visitor coach Name: "; 
          cin >> newCoachName; 
          tTwo.setCoachName(newCoachName); 
      }
        if(userChoice == "F" || userChoice == "f")
      {
         
        //Dr_T challenge Accept a new name for s's home team
        cout << "****Update Challenger Team Score module*** " << endl; 
        cout << "\nPlease enter a new name for the Challenger team: ";
        cin >> color >> newName >> reset;
        //change that home team's default name
        tTwo.setName(newName); //set tOne's data to the new desired name
        }
      else if(userChoice == "L" || userChoice == "l")
      {
        //Dr_T challenge Accept a new name for s's home team
        cout << "****Update Challenger Team Score module*** " << endl; 
        cout << "\nPlease enter Challenger City: ";
        cin >> newCity; 
        //change that home team's default name
        tTwo.setCity(newCity); //
        }
         else if(userChoice == "M" || userChoice == "m")
      {
          cout << "\nUpdate Challenger Coach Module****" << endl; 
          cout << "\nPlease enter the challenger coach Name: "; 
          cin >> newCoachName; 
          tTwo.setCoachName(newCoachName); 
      }
           else if(userChoice == "X" || userChoice == "x")
      {
        cout << "\nUpdate Home Timeout Module****" << endl; 
        cout << "\nPlease enter a new Timeout count for the Challengerteam: "; 
        cin >> newOuts; 
        tTwo.setTimeouts(newOuts);  //set the new score for tOne        
      }
      else if(userChoice == "E" || userChoice == "e")
      {
        cout << "Exit chosen." << endl; 
      }
      else //invalid input: default clause
      {
        cout << "\nInvalid input." << endl; 
        sleep(2); //wait two seconds, go to the next process 
      }

      s.setHome(tOne); //refresh the data in s to the new updates...
      s.setVisitor(tTwo); //refresh the data
     
  }while(userChoice != "E" && userChoice != "e");


  return 0; 
}