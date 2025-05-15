#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Team {
    string name;
    int played;
    int won;
    int drawn;
    int lost;
    int points;

    Team(string n) : name(n), played(0), won(0), drawn(0), lost(0), points(0) {}
};

bool compareTeams(const Team &a, const Team &b) {
    return a.points > b.points; // Urutkan berdasarkan poin tertinggi
}

void displayStandings(const vector<Team> &teams) {
    cout << "Klasemen Liga 1 Indonesia:\n";
    cout << "No\tTim\t\tMain\tMenang\tSeri\tKalah\tPoin\n";
    for (size_t i = 0; i < teams.size(); ++i) {
        cout << i + 1 << "\t" << teams[i].name << "\t\t"
             << teams[i].played << "\t" << teams[i].won << "\t"
             << teams[i].drawn << "\t" << teams[i].lost << "\t"
             << teams[i].points << "\n";
    }
}

void updateTeam(Team &team, int result) {
    team.played++;
    if (result == 1) { // Menang
        team.won++;
        team.points += 3;
    } else if (result == 0) { // Seri
        team.drawn++;
        team.points += 1;
    } else if (result == -1) { // Kalah
        team.lost++;
    }
}

int main() {
    vector<Team> teams;
    int numTeams;

    cout << "Masukkan jumlah tim: ";
    cin >> numTeams;

    // Input nama tim
    for (int i = 0; i < numTeams; ++i) {
        string teamName;
        cout << "Masukkan nama tim " << i + 1 << ": ";
        cin >> teamName;
        teams.emplace_back(teamName);
    }

    // Input hasil pertandingan
    for (int i = 0; i < numTeams; ++i) {
        for (int j = 0; j < numTeams; ++j) {
            if (i != j) {
                int result;
                cout << "Hasil pertandingan " << teams[i].name << " vs " << teams[j].name << " (1: Menang, 0: Seri, -1: Kalah): ";
                cin >> result;
                updateTeam(teams[i], result);
                updateTeam(teams[j], -result); // Update tim lawan
            }
        }
    }

    // Urutkan tim berdasarkan poin
    sort(teams.begin(), teams.end(), compareTeams);

    // Tampilkan klasemen
    displayStandings(teams);

    return 0;
}
