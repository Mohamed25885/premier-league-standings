#include <bits/stdc++.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "graph.hpp"
#include "hydrator.hpp"
#include "standing.hpp"
#include "team.hpp"
#include "sort_vector.hpp"

int main(int argc, char const *argv[])
{
    int num = -1;
    std::time_t intDate = 0;
    std::string date;
    for (int i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "-w"))
        {
            num = std::atoi(argv[i + 1]);
            break;
        }
        else if (!strcmp(argv[i], "-d"))
        {
            date = argv[i + 1];

            std::tm tm = {};
            std::istringstream iss(date);
            iss >> std::get_time(&tm, "%d/%m/%Y");
            intDate = std::mktime(&tm);
            break;
        }
    }

    Graph graph = Graph();
    std::vector<std::vector<std::string>> content = hydrator(graph, "epl_results.csv");

    for (int i = 1; i < content.size(); i++)
    {
        graph.add_match(content[i], num, intDate);
    }

    std::vector<Standing *> standings = graph.dfs();
    std::sort(standings.begin(), standings.end(), sortv());
    std::string HEADERS = "Team, Matches, Win, Draw, Lose, GF, GA, GD, Points";
    std::cout << HEADERS << std::endl;
    std::ofstream output;
    output.open("result.csv");
    output << HEADERS << "\n";
    for (auto entry : standings)
    {
        std::cout << entry->team.getTitle() << ", " << entry->getMatches() << ", " << entry->getWin() << ", " << entry->getDraw() << ", " << entry->getLose() << ", " << entry->getGoalsScored() << ", " << entry->getGoalsRecived() << ", " << entry->getGoalDiff() << ", " << entry->getPoints() << std::endl;
        output << entry->team.getTitle() << "," << entry->getMatches() << "," << entry->getWin() << "," << entry->getDraw() << "," << entry->getLose() << "," << entry->getGoalsScored() << "," << entry->getGoalsRecived() << "," << entry->getGoalDiff() << "," << entry->getPoints() << "\n";
    }
    output.close();
    return 0;
}
