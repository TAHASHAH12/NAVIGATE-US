#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "path.h"
#include <set>

#include <vector>
using namespace std;
int fun(int s, int d);
class travel // for travel pointer
{
public:
    // filing for graphs  using csv file data
    travel *next;

    travel()
    {
        this->next = NULL;
    }
};

class navigation : public travel // class for filing
{
public:
    int choice2, option, count = 0;
    string un, uno, mydata;
    string uname, passw;
    void walk()
    {
        float time, avg_velocity = 1.3, total_distance; // distance will be assigned from filing
        string city1, city2, city3, city4, distance1, distance2;
        int op1, op2, op;
        float s1, s2;
        cout << "YOUR LOCATION: " << endl;

        ifstream data("data.txt");
        while (getline(data, mydata))
        {
            cout << mydata << endl;
        }
        data.close();
        cin >> op1;
        ifstream d("data.txt");
        while (d >> op >> city1)
        {

            if (op == op1)
            {
                cout << "YOUR LOCATION: " << city1 << endl;
                goto l;
            }
        }
    l:
        d.close();
        cout << "CHOOSE Your Destination " << endl;
        cin >> op2;
        ifstream d2("data.txt");
        while (d2 >> op >> city2)
        {

            if (op == op2)
            {

                cout << "YOUR DESTINATION:" << city2 << endl;
                goto g;
            }
        }
    g:
        d2.close();
        total_distance = fun(op1, op2);

        time = total_distance / avg_velocity;
        cout << endl
             << "TIME TO REACH DESTINATION: " << total_distance / 3600 << " Hours approx." << endl;
        exit(0);
    }
    void car()
    {
        float time, avg_velocity = 8.3, distance; // distance will be assigned from filing
        string city1, city2;
        int op, op2, op3;
        int countt;
        cout << "YOUR LOCATION:" << endl;
        ifstream data("data.txt");
        while (getline(data, mydata))
        {
            cout << mydata << endl;
        }
        data.close();
        cin >> op;
        ifstream f("data.txt");
        while (f >> op3 >> city1)
        {
            if (op == op3)
            {
                countt = 1;
                goto w;
            }
        }
    w:
        f.close();
        if (countt == 1)
        {
            cout << "YOUR LOCATION: " << city1 << endl;
        }
        cout << "CHOOSE Your Destination " << endl;
        cin >> op2;
        ifstream p("data.txt");
        while (p >> op3 >> city2)
        {
            if (op2 == op3)
            {
                countt = 1;
                goto q;
            }
        }
    q:
        f.close();
        distance = fun(op, op2);

        time = distance / avg_velocity;
        cout << endl
             << "\nTIME TO REACH DESTINATION: " << time << " hours approx." << endl;
        exit(0);
    }
    void bike()
    {
        float time, avg_velocity = 1.3, total_distance; // distance will be assigned from filing
        string city1, city2, city3, city4, distance1, distance2;
        int op1, op2, op;
        float s1, s2;
        cout << "YOUR LOCATION: " << endl;

        ifstream data("data.txt");
        while (getline(data, mydata))
        {
            cout << mydata << endl;
        }
        data.close();
        cin >> op1;
        ifstream d("data.txt");
        while (d >> op >> city1)
        {

            if (op == op1)
            {
                cout << "YOUR LOCATION: " << city1 << endl;
                goto l;
            }
        }
    l:
        d.close();
        cout << "CHOOSE Your Destination " << endl;
        cin >> op2;
        ifstream d2("data.txt");
        while (d2 >> op >> city2)
        {

            if (op == op2)
            {

                cout << "YOUR DESTINATION:" << city2 << endl;
                goto g;
            }
        }
    g:
        d2.close();
        total_distance = fun(op1, op2);

        time = total_distance / avg_velocity;
        cout << endl
             << "TIME TO REACH DESTINATION: " << total_distance / 3600 << " Hours approx." << endl;
        exit(0);
    }
    void user()
    {
        string username, password, user, pass;
        int count = 0;

        cout << "\nSelect the option  from below " << endl;
        cout << " 1) SIGN IN \n 2) SIGN UP " << endl;
        cin >> option;
        switch (option)
        {
        case 1:
        {
        x:
            cout << "\nEnter username: ";
            cin >> username;
            cout << "\nEnter password: ";
            cin >> password;
            ifstream myfile("userData.bin");
            while (myfile >> user >> pass)
            {
                if (user == username && pass == password)
                {
                    count = 1;
                    un = username;
                }
            }
            myfile.close();
            if (count == 1)
            {
                cout << "\nLogin successful" << endl;
            }

            else
            {
                cout << "Try again" << endl;
                goto x;
            }
        }
        break;

        case 2:
        {
        z:
            cout << "\nEnter username: ";
            cin >> uname;
            ifstream hello("userData.bin");
            while (hello >> uno)
            {
                if (uno == uname)
                {
                    cout << "\nThe username already exits!" << endl;
                    goto z;
                }
            }
            hello.close();

            cout << "\nEnter password: ";
            cin >> passw;

            ofstream file("userData.bin", ios::binary | ios::app);
            file << uname << " " << passw << endl;
            file.close();
            cout << "\nRegistration successful" << endl;
            ofstream files;
            files.open(uname + ".txt", ios::out);
            files.close();
            goto x;
        }

        default:
            cout << "Invalid Selection! " << endl;
            break;
        }

        // till here
        cout << "\nSELECT MODE OF TRANSPORT: " << endl;
        cout << " 1) By walk \n 2) By car \n 3) By cycle or Bike\n";
        cin >> choice2;
        system("pause");
        // system("cls");
        switch (choice2)
        {
        case 1:
            walk();
            break;
        case 2:
            car();

        case 3:
            bike();

        default:
            cout << "Invalid Selection " << endl;
            break;
        }
    }
    int fun(int s, int d)
    {
        int n = 0, m = 5, sd = 0;
        string ch;

        int vis2[10000] = {0};

        ifstream f1;
        int x, y, wt;
        vector<int> w;
        f1.open("dis2.txt");
        while (f1 >> x >> y >> wt)
        {
            w.push_back(wt);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        f1.close();

        vector<int> path;

        string city, city1, city2, pth;
        int op, op1, op2, w1, w2;
        path.push_back(s);
        dfs(vis2, s, d, path);

        cout << endl;

        ifstream f2;

        for (int i = 0; i < vect1.size() - 1; i++)
        {

            for (int j = 0; j < vect1.size() - i - 1; j++)
            {

                if (vect1[j][vect1[j].size() - 1] > vect1[j + 1][vect1[j + 1].size() - 1])
                {

                    swap(vect1[j], vect1[j + 1]);
                }
            }
        }

        cout << "DISTANCE TO DESTINATION: " << endl;
        n = 0;

        for (int i = 0; i < vect1[0].size() - 1; i++)
        {
            f2.open("data.txt");

            while (f2 >> op >> city)
            {

                if (op == vect1[0][i])
                {

                    city1 = city;
                    pth = pth + city + ",";
                }
            }
            f2.close();
            cout << city1 << " ";

            n = i;
        }
        cout << endl
             << endl
             << pth << "Hi";

        cout << vect1[0][n + 1];
        sd = vect1[0][n + 1];
        cout << endl;
    i:
        cout << "\nARE YOU FACING ANY AMBGUITY i.e: ACCIDENT|TRAFFIC: 'YES OR NO'" << endl;
        cin >> ch;
        if (ch == "yes" || ch == "Yes")
        {

            for (int i = 0; i < vect1.size() - 1; i++)
            {

                for (int j = 0; j < vect1.size() - i - 1; j++)
                {

                    if (vect1[j][vect1[j].size() - 1] < vect1[j + 1][vect1[j + 1].size() - 1])
                    {

                        swap(vect1[j], vect1[j + 1]);
                    }
                }
            }
            vect1.pop_back();
            for (int i = 0; i < vect1.size() - 1; i++)
            {

                for (int j = 0; j < vect1.size() - i - 1; j++)
                {

                    if (vect1[j][vect1[j].size() - 1] > vect1[j + 1][vect1[j + 1].size() - 1])
                    {

                        swap(vect1[j], vect1[j + 1]);
                    }
                }
            }

            cout << "\nDISTANCE TO DESTINATION: " << endl;
            n = 0;
            pth = "";
            for (int i = 0; i < vect1[0].size() - 1; i++)
            {
                f2.open("data.txt");

                while (f2 >> op >> city)
                {

                    if (op == vect1[0][i])
                    {

                        city1 = city;
                        pth = pth + city + ",";
                    }
                }
                f2.close();
                cout << city1 << " ";

                n = i;
            }

            cout << vect1[0][n + 1];
            sd = vect1[0][n + 1];
            cout << endl;
            ch.clear();
            ofstream file("out.txt", ios::binary | ios::trunc);
            file << pth;
            file.close();
            system("python ROUTEGRAPH.py out.txt");
            goto i;
            return sd;
        }
        else if (ch == "no" || ch == "NO")
        {
            // cout << "Program closed " << endl;
            ofstream file("out.txt", ios::binary | ios::trunc);
            file << pth;
            file.close();
            system("python ROUTEGRAPH.py out.txt");
            return sd;
            exit(0);
        }
        else
        {
            cout << "Invalid choice " << endl;
            goto i;
        }
    }
    void display()
    {

        string city, city1, city2;
        int op, op1, op2, w1, w2, n = 0;

        ifstream f2;
        for (int i = 0; i < vect1.size(); i++)
        {

            for (int j = 0; j < vect1[i].size() - 1; j++)
            {
                f2.open("data.txt");

                while (f2 >> op >> city)
                {

                    if (op == vect1[i][j])
                    {

                        city1 = city;
                    }
                }
                f2.close();
                cout << city1 << " ";
                n = j;
            }
            cout << vect1[i][n + 1];
            cout << endl;
        }
    }
};

int main()
{
    navigation f;
    int choice1;
    // system("color fc");
    cout << "\t\t\t\t\t Welcome to Navigate us: \t\t\t\t\t" << endl;

    system("pause");
    cout << "\nPROJECT BY:\n 1) Taha shah \n 2) Mir Osama Ali \n 3) Jalil Abbas\n"
         << endl;
    system("pause");
    f.user();
}