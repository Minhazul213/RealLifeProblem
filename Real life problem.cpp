#include <iostream>
#include <algorithm>
using namespace std;
void sortDescending(int people[], int camps) {
    sort(people, people + camps, greater<int>());
}
void calculateAndDisplay(int totalPeople, int foodPackets) {
    if (totalPeople > foodPackets) {
        int shortage = totalPeople - foodPackets;
        cout << "Total " << totalPeople << " people are present, which requires " << shortage << " more packets than the " << foodPackets << " available packets." << endl;
    } else if (totalPeople < foodPackets) {
        int extraPackets = foodPackets - totalPeople;
        cout << "Total " << totalPeople << " people are present, and there will be " << extraPackets << " extra packets." << endl;
    } else {
        cout << "Total " << totalPeople << " people are present and all packets are sufficient." << endl;
    }
}
void checkUrgency(int campNumber, int people[], int& camps, int& foodPackets) {
    if (campNumber > 0 && campNumber <= camps) {
        cout << "Camp " << campNumber << " has " << people[campNumber - 1] << " people." << endl;

        int requiredPackets = people[campNumber - 1];
        if (foodPackets >= requiredPackets) {
            foodPackets -= requiredPackets;
            cout << "Distribute " << requiredPackets << " packets to Camp " << campNumber << "." << endl;
            cout << "Remaining packets: " << foodPackets << endl;
            for (int i = campNumber - 1; i < camps - 1; i++) {
                people[i] = people[i + 1];
            }
            camps--;


            int totalPeople = 0;
            for (int i = 0; i < camps; i++) {
                totalPeople += people[i];
            }


            calculateAndDisplay(totalPeople, foodPackets);
        } else {
            cout << "Not enough packets. Packets required: " << requiredPackets << endl;
        }
    } else {
        cout << "Invalid camp number." << endl;
    }
}

int main() {
    int camps;
    int foodPackets;
    cout << "Enter the number of camps: ";
    cin >> camps;

    cout << "Enter the number of food packets: ";
    cin >> foodPackets;

    int people[camps];
    int totalPeople = 0;
    for (int i = 0; i < camps; i++) {
        cout << "Enter the number of people in Camp " << i + 1 << ": ";
        cin >> people[i];
        totalPeople += people[i];
    }
    calculateAndDisplay(totalPeople, foodPackets);
    sortDescending(people, camps);

    cout << "Camps sorted by number of people (descending):\n";
    for (int i = 0; i < camps; i++) {
        cout << "Camp " << i + 1 << " has " << people[i] << " people." << endl;
    }

    int urgentCamp;
    while (camps > 0) {
        cout << "Enter the camp number for urgent relief distribution (1-" << camps << "): ";
        cin >> urgentCamp;
        checkUrgency(urgentCamp, people, camps, foodPackets);


        sortDescending(people, camps);

        cout << "Camps sorted by number of people (descending):\n";
        for (int i = 0; i < camps; i++) {
            cout << "Camp " << i + 1 << " has " << people[i] << " people." << endl;
        }

        if (camps == 0) {
            cout << "Relief distribution completed in all camps." << endl;
            break;
        }
    }

    return 0;
}
