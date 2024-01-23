#include<iostream>
#include<windows.h>
const int MAX_BUSES = 10; // Maximum number of buses
const int MAX_STOPS=118;
using namespace std;

string R1[] = { "Model Colony Mor", "Model Mor", "Malir Halt", "Colony Gate", "Nata Khan Bridge", "Drigh Road Station", "PAF Base Faisal", "Laal Kothi", "Karsaz", "Nursery", "FTC", "Regent Plaza", "Metropole", "Fawwara Chowk", "Arts Council", "Shaheen Complex", "I.I.Chundrigar", "Tower", "Fisheries", "Dockyard" };
string R2[] = { "Nagan Chowrangi", "Shafiq Morr", "Sohrab Goth", "Gulshan Chowranei", "NIPA", "Johar Morr", "COD", "Drigh Road Station", "Colony Gate", "Shah Faisal Colony", "Singer Chowrangi", "Landhi Road" };
string R3[] = { "Power House", "UP More", "Nagan Chowrangi", "Sakhi Hasan", "5 Star Chowrangi", "KDA Chowrangi", "Nazimabad Eid Gah Ground", "Liaquatabad 10 Number", "Essa Nagri", "Civic Centre", "National stadium", "Karsaz", "Nursery", "FTC", "Korangi Road", "KPT Interchange upto Shan Chowrangi" };
string R4[] = { "Power House", "UP Mor", "Nagan Chowrangi", "Shafiq Mor", "Sohrab Goth", "Shahrah e Pakistan", "Ayesha Manzil", "Liaqautabad 10", "Laloo Khait", "Teen Hati", "Jehangir Road", "Numaish", "Mobile Market", "Urdu Bazar", "Civil Hospital", "City Court", "Light House", "Bolton Market", "Tower" };
string R9[] = { "Salah Uddin Ayubi Road", "Allah Wali Chowrangi", "National Highway 5", "Steel Mill More", "Port Bin Qasim More", "Razzakabad", "Abdullah Goth", "Chowkundi More", "Fast University", "Bhains Colony More", "Manzil Pump", "Quaidabad", "Murghi Khana", "Prince Aly Boys School", "Nadra Center Malir", "Malir Session Court", "Malir 15", "Kalaboard", "Malir Halt", "Colony Gate", "Nata Khan Bridge", "Drigh Road Station", "PAF Base Faisal", "Laal Kothi", "Karsaz", "Nursery", "FTC", "Regent Plaza", "Metropole", "Fawwara Chowk", "Arts Council", "Shaheen Complex", "I.I.Chundrigar" };
string R10[] = { "Numaish", "Taj Complex", "Capri Cinema", "Mobile Market", "Regal", "Abdullah Haroon", "Zainab Market", "Fawara Chowk", "Metropole", "Frere Hall", "PSO Head Office", "3 Talwar", "Ocean Mall", "2 Talwar", "Abdullah Shah Ghazi Mazar", "Bagh Ibn E Qasim", "Dolmen Mall Cilfton", "Seaview Clock Tower", "Khayaban e Ittehad", "DHA Phase 7", "DHA Phase 6", "DHA Phase 2", "KPT Interchange", "Korangi Crossing", "Indus Hospital", "CBM University", "PARCO", "Ibrahim Hyderi" };
string R11[] = { "Bilawal Chowrangi", "26th Street", "Khadda Market", "Gizri Road", "Submarine Chowk", "Eidgah Clifton", "PIDC", "Haji Camp", "US Consulate General", "M.T. Khan Road", "Mauripur", "Keamari", "Lyari" };
string R12[] = { "Naddi Kinara", "Khokhrapar", "Saudabad Chowrangi", "RCD Ground", "Kalaboard", "Malir 15", "Malir Mandir", "Malir Session Court", "Murghi Khana", "Quaidabad", "Dawood Chowrangi", "Babar Market", "Landhi Road", "Nasir Jump", "Indus Hospital", "Korangi Crossing", "Qayyumabad", "Defence Mor", "National Medical Center", "Gora Qabristan", "FTC", "Jutt Land", "Lines Area", "Army Public School", "Lucky Star Saddar" };
string EV_1[] = { "CMH Malir Cantt", "Tank Chowk", "Model Colony Mor", "Jinnah Ave", "Airport", "Colony Gate", "Nata Khan Bridge", "Drigh Road Station", "PAF Base Faisal", "Laal Kothi", "Karsaz", "Nursery", "FTC", "Korangi Road", "DHA Phase 1", "Masjid e Ayesha", "Clock Tower DHA", "Dolmen Mall Clifton" };
string EV_2[] = { "Bahria Town", "Damba Goth", "Toll Plaza", "Baqai University", "Malir Cantt Gate 5", "Malir Cantt Gate 6", "Tank Chowk", "Model Mor", "Jinnah Ave", "Malir Halt" };
string EV_3[] = { "Malir Cantt Check Post 5", "Rim Jhim Tower", "Safoora Chowrangi", "Mausamiyat Chowrangi", "Kamran Chowrangi", "Johar Chowrangi", "Johar Mor", "Millennium Mall", "Dalmia Road", "Bahria University", "National Stadium", "Aga Khan Hospital", "Liaquat National Hospital", "PIB Colony", "Jail Chowrangi", "Dawood Engineering University", "Islamia College", "People Secretariat Chowrangi", "Numaish" };
class node {
public:
    int stop;
    int buses[MAX_BUSES];

    node* nextstop;

    node(int d) {
        stop = d;
        nextstop = NULL;
        for (int i = 0; i < MAX_BUSES; ++i) {
            buses[i] = -1; // Initialize buses to -1 (indicating no bus)
        }
    }
};

string getStopName(int stopNumber) {
    string stops[] = {
        "Salah Uddin Ayubi Road", "Allah Wali Chowrangi", "National Highway 5", "Steel Mill More",
        "Port Bin Qasim More", "Razzakabad", "Abdullah Goth", "Chowkundi More", "Fast University",
        "Bhains Colony More", "Manzil Pump", "Quaidabad", "Murghi Khana", "Prince Aly Boys School",
        "Nadra Center Malir", "Malir Session Court", "Malir 15", "Kalaboard", "Malir Halt",
        "Colony Gate", "Nata Khan Bridge", "Drigh Road Station", "PAF Base Faisal", "Laal Kothi",
        "Karsaz", "Nursery", "FTC", "Regent Plaza", "Metropole", "Fawwara Chowk", "Arts Council",
        "Shaheen Complex", "I.I.Chundrigar", "Bilawal Chowrangi", "26th Street", "Khadda Market",
        "Gizri Road", "Submarine Chowk", "Eidgah Clifton", "PIDC", "Haji Camp", "US Consulate General",
        "M.T. Khan Road", "Mauripur", "Keamari", "Lyari", "Naddi Kinara", "Khokhrapar",
        "Saudabad Chowrangi", "RCD Ground", "Kalaboard", "Malir 15", "Malir Mandir", "Malir Session Court",
        "Murghi Khana", "Quaidabad", "Dawood Chowrangi", "Babar Market", "Landhi Road", "Nasir Jump",
        "Indus Hospital", "Korangi Crossing", "Qayyumabad", "Defence Mor", "National Medical Center",
        "Gora Qabristan", "FTC", "Jutt Land", "Lines Area", "Army Public School", "Lucky Star Saddar",
        "CMH Malir Cantt", "Tank Chowk", "Model Colony Mor", "Jinnah Ave", "Airport", "Colony Gate",
        "Nata Khan Bridge", "Drigh Road Station", "PAF Base Faisal", "Laal Kothi", "Karsaz", "Nursery",
        "FTC", "Korangi Road", "DHA Phase 1", "Masjid e Ayesha", "Clock Tower DHA", "Dolmen Mall Clifton",
        "Bahria Town", "Damba Goth", "Toll Plaza", "Baqai University", "Malir Cantt Gate 5", "Malir Cantt Gate 6",
        "Tank Chowk", "Model Mor", "Jinnah Ave", "Malir Halt", "Malir Cantt Check Post 5", "Rim Jhim Tower",
        "Safoora Chowrangi", "Mausamiyat Chowrangi", "Kamran Chowrangi", "Johar Chowrangi", "Johar Mor",
        "Millennium Mall", "Dalmia Road", "Bahria University", "National Stadium", "Aga Khan Hospital",
        "Liaquat National Hospital", "PIB Colony", "Jail Chowrangi", "Dawood Engineering University",
        "Islamia College", "People Secretariat Chowrangi", "Numaish"
    };

    // Check if the stopNumber is within valid range
    if (stopNumber >= 1 && stopNumber <= 118) {
        return stops[stopNumber - 1];  // Arrays are 0-indexed, stop numbers start from 1
    }
    else {
        return "Invalid stop number";
    }
}
int getStopNumber(string stop) {
    std::string stops[] = {
        "Salah Uddin Ayubi Road", "Allah Wali Chowrangi", "National Highway 5", "Steel Mill More",
        "Port Bin Qasim More", "Razzakabad", "Abdullah Goth", "Chowkundi More", "Fast University",
        "Bhains Colony More", "Manzil Pump", "Quaidabad", "Murghi Khana", "Prince Aly Boys School",
        "Nadra Center Malir", "Malir Session Court", "Malir 15", "Kalaboard", "Malir Halt",
        "Colony Gate", "Nata Khan Bridge", "Drigh Road Station", "PAF Base Faisal", "Laal Kothi",
        "Karsaz", "Nursery", "FTC", "Regent Plaza", "Metropole", "Fawwara Chowk", "Arts Council",
        "Shaheen Complex", "I.I.Chundrigar", "Bilawal Chowrangi", "26th Street", "Khadda Market",
        "Gizri Road", "Submarine Chowk", "Eidgah Clifton", "PIDC", "Haji Camp", "US Consulate General",
        "M.T. Khan Road", "Mauripur", "Keamari", "Lyari", "Naddi Kinara", "Khokhrapar",
        "Saudabad Chowrangi", "RCD Ground", "Kalaboard", "Malir 15", "Malir Mandir", "Malir Session Court",
        "Murghi Khana", "Quaidabad", "Dawood Chowrangi", "Babar Market", "Landhi Road", "Nasir Jump",
        "Indus Hospital", "Korangi Crossing", "Qayyumabad", "Defence Mor", "National Medical Center",
        "Gora Qabristan", "FTC", "Jutt Land", "Lines Area", "Army Public School", "Lucky Star Saddar",
        "CMH Malir Cantt", "Tank Chowk", "Model Colony Mor", "Jinnah Ave", "Airport", "Colony Gate",
        "Nata Khan Bridge", "Drigh Road Station", "PAF Base Faisal", "Laal Kothi", "Karsaz", "Nursery",
        "FTC", "Korangi Road", "DHA Phase 1", "Masjid e Ayesha", "Clock Tower DHA", "Dolmen Mall Clifton",
        "Bahria Town", "Damba Goth", "Toll Plaza", "Baqai University", "Malir Cantt Gate 5", "Malir Cantt Gate 6",
        "Tank Chowk", "Model Mor", "Jinnah Ave", "Malir Halt", "Malir Cantt Check Post 5", "Rim Jhim Tower",
        "Safoora Chowrangi", "Mausamiyat Chowrangi", "Kamran Chowrangi", "Johar Chowrangi", "Johar Mor",
        "Millennium Mall", "Dalmia Road", "Bahria University", "National Stadium", "Aga Khan Hospital",
        "Liaquat National Hospital", "PIB Colony", "Jail Chowrangi", "Dawood Engineering University",
        "Islamia College", "People Secretariat Chowrangi", "Numaish"
    };
    for (int i = 0;i < MAX_STOPS;i++) {
        if (stop == stops[i]) {
            return (i + 1);
        }
    }
   
}
string getBusName(int busNumber) {
    string busNames[] = {
        "R1", "R2", "R3", "R4", "R9", "R11", "R12", "EV_1", "EV_2", "EV_3"
    };

    // Check if the busNumber is within valid range
    if (busNumber >= 1 && busNumber <= 10) {
        return busNames[busNumber - 1];  // Arrays are 0-indexed, bus numbers start from 1
    }
    else {
        return "Invalid bus number";
    }
}

class RouteFinder {
public:
    
    node* BusStop;
    RouteFinder(int maxStops) {
        //MAX_STOPS = maxStops - 1;
        BusStop = new node(1);
        node* currentStop = BusStop;

        for (int i = 2; i <= MAX_STOPS; ++i) {
            currentStop->nextstop = new node(i);
            currentStop = currentStop->nextstop;
        }
    }
    void addBusRoute(string route[], int size, int busNo) {
        node* current = BusStop;
        int i = 0;

        while (current != NULL && i < size) {
            node* current2 = BusStop;

            while (current2 != NULL && current2->stop != getStopNumber( route[i])) {
                current2 = current2->nextstop;
            }

            if (current2 != NULL && current2->stop == getStopNumber(route[i])) {
                for (int j = 0; j < MAX_BUSES; j++) {
                    if (current2->buses[j] == -1) {
                        current2->buses[j] = busNo;
                        break;
                    }
                }
            }
            i++;
            current = current->nextstop;
        }
    }

    void FindRoute(int source, int destination) {

        node* current = BusStop;
        bool found = false;

        node* src = BusStop;
        node* dest = BusStop;
//        if (source > destination) {
//            swap(source, destination);
//        }
		if(source != 1){
        do {
            src = src->nextstop;
        } while (src->stop != source);
		}
		if(destination != 1){
        do {
            dest = dest->nextstop;
        } while (dest->stop != destination);
        }
        for (int i = 0;i < MAX_BUSES;i++) {
            for (int j = 0;j < MAX_BUSES;j++) {
                if (src->buses[i] == dest->buses[j] && src->buses[i]!=-1) {
                    //cout << src->buses[i] << " " << dest->buses[j] << endl;
                    cout << "Direct Route " << getStopName(source) << " to " << getStopName(destination)<< " via Bus " << getBusName( dest->buses[j] )<< endl;
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            cout << "No direct route found between stop " << getStopName(source) << " and stop " << getStopName(destination) << endl;
            if (source >= destination) {
                findConnectorBuses(dest, src);
            }
            else {
                findConnectorBuses(src, dest);
            }
        }

    }
    bool common(node* n1, node* n2, int* common) {
        int c = 0;
        for (int i = 0; i < MAX_BUSES; i++) {
            if (n1->buses[i] == -1) {
                continue;
            }
            else {
                for (int j = 0; j < MAX_BUSES; j++) {
                    if (n1->buses[i] == n2->buses[j]) {
                        common[c++] = n1->buses[i];
                        break;
                    }
                }
            }
        }
        return c > 0; // Return true if there are common buses
    }

    void findConnectorBuses(node* source, node* destination) {
        int foundBuses[MAX_STOPS][MAX_BUSES] = { 0 };
        node* current = source;

        while (current != destination->nextstop && current->nextstop != NULL) {
            int commonBuses[MAX_BUSES] = { 0 };
            if (common(current, current->nextstop, commonBuses)) {
                foundBuses[current->stop - 1] [commonBuses[0] - 1] = 1;
            }
            current = current->nextstop;
        }

        cout << "Connector buses between stop " << source->stop << " and stop " << destination->stop << ": \n";
        int bus=0;
        for (int i = 0; i < MAX_STOPS; ++i) {
            for (int j = 0; j < MAX_BUSES; ++j) {
                if (foundBuses[i][j] == 1 &&  j!=bus) {
                    cout << "\nBus: " << getBusName( j + 1) << " ";
                    bus = j;
                    node* current2 = source;
                    while (current2!=destination->nextstop)
                    {
                        for (int k = 0; k < MAX_BUSES; k ++ ) {
                            if (current2->buses[k] == j + 1) {
                                cout << current2->stop <<" ->";
                            }
                        }
                        current2 = current2->nextstop;
                    }
                    break;
                }
            }
        }
        int bus2 = 0;
        cout << "\nYou Can Travel through Buses :" << endl;
        for (int i = 0;i < MAX_STOPS;i++) {
            for (int j = 0; j < MAX_BUSES; ++j) {
                if (foundBuses[i][j] == 1 && j != bus2) {
                    cout << getBusName(j + 1) << " ";
                    bus2 = j;
                }
                
            }
        }
        cout << endl;
    }
    void Print() {
        node* crr = BusStop;
        while (crr != NULL) {
            cout  << getStopName(crr->stop) << " : ";
            for (int i = 0;i < MAX_BUSES;i++) {
                if (crr->buses[i] != -1) {
                    cout << getBusName(crr->buses[i]) << " , ";
                }
            }
            cout << endl;
            crr = crr->nextstop;
        }
    }
};
void BusRoutes();
void FindRoutes();
void GiveFeedBack();
void goodBye();
void welcome();
void mainScreen();


void StopRoutes(){
	cout << "----------------------------------------------------------------\n";
	cout << "---------------------- ALL STOPS NAMES -------------------------\n";
	cout << "----------------------------------------------------------------\n";
	cout << "1. Salah Uddin Ayubi Road\t2. Allah Wali Chowrangi\t3. National Highway 5\t4. Steel Mill More\n"
        "5. Port Bin Qasim More\t6. Razzakabad\t7. Abdullah Goth\t8. Chowkundi More\n"
        "9. Fast University\t10. Bhains Colony More\t11. Manzil Pump\t12. Quaidabad\n"
        "13. Murghi Khana\t14. Prince Aly Boys School\t15. Nadra Center Malir\t16. Malir Session Court\n"
        "17. Malir 15\t18. Kalaboard\t19. Malir Halt\t20. Colony Gate\n"
        "21. Nata Khan Bridge\t22. Drigh Road Station\t23. PAF Base Faisal\t24. Laal Kothi\n"
        "25. Karsaz\t26. Nursery\t27. FTC\t28. Regent Plaza\n"
        "29. Metropole\t30. Fawwara Chowk\t31. Arts Council\t32. Shaheen Complex\n"
        "33. I.I.Chundrigar\t34. Bilawal Chowrangi\t35. 26th Street\t36. Khadda Market\n"
        "37. Gizri Road\t38. Submarine Chowk\t39. Eidgah Clifton\t40. PIDC\n"
        "41. Haji Camp\t42. US Consulate General\t43. M.T. Khan Road\t44. Mauripur\n"
        "45. Keamari\t46. Lyari\t47. Naddi Kinara\t48. Khokhrapar\n"
        "49. Saudabad Chowrangi\t50. RCD Ground\t51. Kalaboard\t52. Malir 15\n"
        "53. Malir Mandir\t54. Malir Session Court\t55. Murghi Khana\t56. Quaidabad\n"
        "57. Dawood Chowrangi\t58. Babar Market\t59. Landhi Road\t60. Nasir Jump\n"
        "61. Indus Hospital\t62. Korangi Crossing\t63. Qayyumabad\t64. Defence Mor\n"
        "65. National Medical Center\t66. Gora Qabristan\t67. FTC\t68. Jutt Land\n"
        "69. Lines Area\t70. Army Public School\t71. Lucky Star Saddar\t72. CMH Malir Cantt\n"
        "73. Tank Chowk\t74. Model Colony Mor\t75. Jinnah Ave\t76. Airport\n"
        "77. Colony Gate\t78. Nata Khan Bridge\t79. Drigh Road Station\t80. PAF Base Faisal\n"
        "81. Laal Kothi\t82. Karsaz\t83. Nursery\t84. FTC\n"
        "85. Korangi Road\t86. DHA Phase 1\t87. Masjid e Ayesha\t88. Clock Tower DHA\n"
        "89. Dolmen Mall Clifton\t90. Bahria Town\t91. Damba Goth\t92. Toll Plaza\n"
        "93. Baqai University\t94. Malir Cantt Gate 5\t95. Malir Cantt Gate 6\t96. Tank Chowk\n"
        "97. Model Mor\t98. Jinnah Ave\t99. Malir Halt\t100. Malir Cantt Check Post 5\n"
        "101. Rim Jhim Tower\t102. Safoora Chowrangi\t103. Mausamiyat Chowrangi\t104. Kamran Chowrangi\n"
        "105. Johar Chowrangi\t106. Johar Mor\t107. Millennium Mall\t108. Dalmia Road\n"
        "109. Bahria University\t110. National Stadium\t111. Aga Khan Hospital\t112. Liaquat National Hospital\n"
        "113. PIB Colony\t114. Jail Chowrangi\t115. Dawood Engineering University\t116. Islamia College\n"
        "117. People Secretariat Chowrangi\t118. Numaish" << endl;
        
        //cout << "\n\n SEE your stop number from this list.\n\n";
        cout<<"\t\t\tPress Any Key To continue...........\t\t\t"<<endl;
		getchar();
}

RouteFinder g(118);
void Find_routes(){
	
	int src , dest;
	cout << "Enter The Stop Number" << endl;
    cin >> src;
    cin >> dest;
    if (src >= 1 && src <= 118 && dest>=1 && dest<=118) {
        g.FindRoute(src, dest);
    }
    else {
        cout << "inValid Source or Destination" << endl;
    }
    
    //g.Print();
	cout<<"\t\t\tPress Any Key To continue...........\t\t\t"<<endl;
	getchar();
}
void Bus_Route(){
	cout<<"\n-----------------------------------------All Red Buses Have Route------------------------------- \n"<<endl;
	cout<< "R1: Model Colony Mor -> Model Mor-> Malir Halt -> Colony Gate->Nata Khan Bridge -?> Drigh Road Station -> PAF Base Faisal -> Laal Kothi-> Karsaz-> Nursery-> FTC-> Regent Plaza-> Metropole-> Fawwara Chowk-> Arts Council-> Shaheen Complex-> I.I.Chundrigar-> Tower-> Fisheries-> Dockyard" <<endl;
    cout<< "R2: Nagan Chowrangi-> Shafiq Morr-> Sohrab Goth-> Gulshan Chowranei-> NIPA-> Johar Morr-> COD-> Drigh Road Station-> Colony Gate-> Shah Faisal Colony-> Singer Chowrangi-> Landhi Road" <<endl;
    cout<< "R3: Power House-> UP More-> Nagan Chowrangi-> Sakhi Hasan-> 5 Star Chowrangi-> KDA Chowrangi-> Nazimabad Eid Gah Ground-> Liaquatabad 10 Number-> Essa Nagri-> Civic Centre-> National stadium-> Karsaz-> Nursery-> FTC-> Korangi Road-> KPT Interchange upto Shan Chowrangi" <<endl;
    cout<< "R4: Power House-> UP Mor-> Nagan Chowrangi-> Shafiq Mor-> Sohrab Goth-> Shahrah e Pakistan-> Ayesha Manzil-> Liaqautabad 10-> Laloo Khait-> Teen Hati-> Jehangir Road-> Numaish-> Mobile Market-> Urdu Bazar-> Civil Hospital-> City Court-> Light House-> Bolton Market-> Tower" <<endl;
    cout<< "R9: Salah Uddin Ayubi Road-> Allah Wali Chowrangi-> National Highway 5-> Steel Mill More-> Port Bin Qasim More-> Razzakabad-> Abdullah Goth-> Chowkundi More-> Fast University-> Bhains Colony More-> Manzil Pump-> Quaidabad-> Murghi Khana-> Prince Aly Boys School-> Nadra Center Malir-> Malir Session Court-> Malir 15-> Kalaboard-> Malir Halt-> Colony Gate-> Nata Khan Bridge-> Drigh Road Station-> PAF Base Faisal-> Laal Kothi-> Karsaz-> Nursery-> FTC-> Regent Plaza-> Metropole-> Fawwara Chowk-> Arts Council-> Shaheen Complex-> I.I.Chundrigar" <<endl;
    cout<< "R10: Numaish-> Taj Complex-> Capri Cinema-> Mobile Market-> Regal-> Abdullah Haroon-> Zainab Market-> Fawara Chowk-> Metropole-> Frere Hall-> PSO Head Office-> 3 Talwar-> Ocean Mall-> 2 Talwar-> Abdullah Shah Ghazi Mazar-> Bagh Ibn E Qasim-> Dolmen Mall Cilfton-> Seaview Clock Tower-> Khayaban e Ittehad-> DHA Phase 7-> DHA Phase 6-> DHA Phase 2-> KPT Interchange-> Korangi Crossing-> Indus Hospital-> CBM University-> PARCO-> Ibrahim Hyderi" <<endl;
    cout<< "R11: Bilawal Chowrangi-> 26th Street-> Khadda Market-> Gizri Road-> Submarine Chowk-> Eidgah Clifton-> PIDC-> Haji Camp-> US Consulate General-> M.T. Khan Road-> Mauripur-> Keamari-> Lyari" <<endl;
    cout<< "R12: Naddi Kinara-> Khokhrapar-> Saudabad Chowrangi-> RCD Ground-> Kalaboard-> Malir 15-> Malir Mandir-> Malir Session Court-> Murghi Khana-> Quaidabad-> Dawood Chowrangi-> Babar Market-> Landhi Road-> Nasir Jump-> Indus Hospital-> Korangi Crossing-> Qayyumabad-> Defence Mor-> National Medical Center-> Gora Qabristan-> FTC-> Jutt Land-> Lines Area-> Army Public School-> Lucky Star Saddar" <<endl;
    cout<<"EV_1: CMH Malir Cantt-> Tank Chowk-> Model Colony Mor-> Jinnah Ave-> Airport-> Colony Gate-> Nata Khan Bridge-> Drigh Road Station-> PAF Base Faisal-> Laal Kothi-> Karsaz-> Nursery-> FTC-> Korangi Road-> DHA Phase 1-> Masjid e Ayesha-> Clock Tower DHA-> Dolmen Mall Clifton" <<endl;
    cout<<"EV_2: Bahria Town-> Damba Goth-> Toll Plaza-> Baqai University-> Malir Cantt Gate 5-> Malir Cantt Gate 6-> Tank Chowk-> Model Mor-> Jinnah Ave-> Malir Halt" <<endl;
    cout<<"EV_3: Malir Cantt Check Post 5-> Rim Jhim Tower-> Safoora Chowrangi-> Mausamiyat Chowrangi-> Kamran Chowrangi-> Johar Chowrangi-> Johar Mor-> Millennium Mall-> Dalmia Road-> Bahria University-> National Stadium-> Aga Khan Hospital-> Liaquat National Hospital-> PIB Colony-> Jail Chowrangi-> Dawood Engineering University-> Islamia College-> People Secretariat Chowrangi-> Numaish" <<endl;
	cout<<"\n\tEnter Any key to Continue.....\n"<<endl;
	getchar();
}


void goodBye(){
	system("CLS");
	system("Color 74");
	cout<<"\n************************************************************************************************************"<<endl;;
	cout<<"*************************************************************************************************************\n\n\n"<<endl;;
	cout<<"\t\t\t---------------Good Bye, Have a nice trip---------------------"<<endl;
	cout<<"\n\n\n**************************************************************************************************************"<<endl;;
	cout<<"**************************************************************************************************************\n\n\n"<<endl;;
	
}
void welcome(){
	system("Color 34");
	cout<<"\n************************************************************************************************************"<<endl;;
	cout<<"*************************************************************************************************************\n\n\n"<<endl;;
	cout<<"\t\t\tWelcome To Karachi Red Bus Route Finder"<<endl;
	cout<<"\n\n\n**************************************************************************************************************"<<endl;;
	cout<<"**************************************************************************************************************\n\n\n"<<endl;;
	cout<<"Project By :"<<endl;
	cout<<"22k-4591 Ayesha Abdul Rahman"<<endl;
	cout<<"22k-4546 Fiza Farooq\n\n"<<endl;
	cout<<"\t\t\tPress Any Key To continue...........\t\t\t"<<endl;
	getchar();
}
void mainScreen(){
    
    int src,dest;
    g.addBusRoute(R1, sizeof(R1) / sizeof(R1[0]), 1);
    g.addBusRoute(R2, sizeof(R2) / sizeof(R2[0]), 2);
    g.addBusRoute(R3, sizeof(R3) / sizeof(R3[0]), 3);
    g.addBusRoute(R4, sizeof(R4) / sizeof(R4[0]), 4);
    g.addBusRoute(R9, sizeof(R9) / sizeof(R9[0]), 5);//R9= 5
    g.addBusRoute(R11, sizeof(R11) / sizeof(R11[0]), 6);//R11=6
    g.addBusRoute(R12, sizeof(R12) / sizeof(R12[0]), 7);//R12=7
    g.addBusRoute(EV_1, sizeof(EV_1) / sizeof(EV_1[0]), 8);//EV1=8
    g.addBusRoute(EV_2, sizeof(EV_2) / sizeof(EV_2[0]), 9);//ev2=9
    g.addBusRoute(EV_3, sizeof(EV_3) / sizeof(EV_3[0]), 10);//ev3=10
    
	system("Color 84");
	int option;
	do{
		system("CLS");	
		cout<<"\n************************************************************************************************************"<<endl;;
		cout<<"*************************************************************************************************************\n\n\n"<<endl;;
		cout<<"\t\t\t\tKarachi Red Bus Route Finder"<<endl;
		cout<<"\n\n\n**************************************************************************************************************"<<endl;;
		cout<<"**************************************************************************************************************\n\n\n"<<endl;;
		cout<<"Select Options"<<endl;
		cout<<"1-Visit All Stops Number"<<endl;
		cout<<"2-Find Route"<<endl;
		cout<<"3-All Bus Route "<<endl;
		cout<<"0-Exit"<<endl;
		cin>>option;
		switch(option){
			case 1:
				system("CLS");	
				StopRoutes();
				getchar();
				break;
			case 2:
				system("CLS");
				StopRoutes();	
				Find_routes();
				getchar();
				break;
			case 3:
				system("CLS");
				Bus_Route();
				getchar();
				break;
			case 0:
				system("CLS");
				goodBye();
				break;
			default:
			cout<<"OOPS!..You wrote something Wrong..."<<endl; 
		}
	}
	while(option!=0);
}


int main(){

	welcome();
	system("CLS");
	mainScreen();
	
}
