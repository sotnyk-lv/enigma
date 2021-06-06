#include <iostream>
#include <vector>
#include <string>

//#define DEBOUT

#include "time_counting.h"

void letters_to_numbers(std::string &text, std::vector<int> &numbers) {
    for (auto &letter: text) {
        numbers.emplace_back(static_cast<int>(letter) - static_cast<int>('A'));
    }
}

void numbers_to_letters(std::string &text, std::vector<int> &numbers) {
    for (auto &number: numbers) {
        text += (static_cast<char>(number + static_cast<int>('A') ));
    }
}

int main() {

    int rotor1_forward[] = {4, 10, 12, 5, 11, 6, 3, 16, 21, 25, 13, 19, 14, 22, 24, 7, 23, 20, 18, 15, 0, 8, 1, 17, 2, 9};
    int rotor1_backward[] = {20, 22, 24, 6, 0, 3, 5, 15, 21, 25, 1, 4, 2, 10, 12, 19, 7, 23, 18, 11, 17, 8, 13, 16, 14, 9};
    int rotor2_forward[] = {0, 9, 3, 10, 18, 8, 17, 20, 23, 1, 11, 7, 22, 19, 12, 2, 16, 6, 25, 13, 15, 24, 5, 21, 14, 4};
    int rotor2_backward[] = {0, 9, 15, 2, 25, 22, 17, 11, 5, 1, 3, 10, 14, 19, 24, 20, 16, 6, 4, 13, 7, 23, 12, 8, 21, 18};
    int rotor3_forward[] = {1, 3, 5, 7, 9, 11, 2, 15, 17, 19, 23, 21, 25, 13, 24, 4, 8, 22, 6, 0, 10, 12, 20, 18, 16, 14};
    int rotor3_backward[] = {19, 0, 6, 1, 15, 2, 18, 3, 16, 4, 20, 5, 21, 13, 25, 7, 24, 8, 23, 9, 22, 11, 17, 10, 14, 12};
    int rotor4_forward[] = {4, 18, 14, 21, 15, 25, 9, 0, 24, 16, 20, 8, 17, 7, 23, 11, 13, 5, 19, 6, 10, 3, 2, 12, 22, 1};
    int rotor4_backward[] = {7, 25, 22, 21, 0, 17, 19, 13, 11, 6, 20, 15, 23, 16, 2, 4, 9, 12, 1, 18, 10, 3, 24, 14, 8, 5};
    int rotor5_forward[] = {21, 25, 1, 17, 6, 8, 19, 24, 20, 15, 18, 3, 13, 7, 11, 23, 0, 22, 12, 9, 16, 14, 5, 4, 2, 10};
    int rotor5_backward[] = {16, 2, 24, 11, 23, 22, 4, 13, 5, 19, 25, 14, 18, 12, 21, 9, 20, 3, 10, 6, 8, 0, 17, 15, 7, 1};

    int rotor1_position = 0;
    int rotor2_position = 0;
    int rotor3_position = 0;
    int rotor4_position = 0;
    int rotor5_position = 0;

    int rotor1_rotation = 17;
    int rotor2_rotation = 5;
    int rotor3_rotation = 22;
    int rotor4_rotation = 10;
    int rotor5_rotation = 0;

    int plugboard[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

    int reflector_UKV_B[] = {24, 17, 20, 7, 16, 18, 11, 3, 15, 23, 13, 6, 14, 10, 12, 8, 4, 1, 5, 25, 2, 22, 21, 9, 0, 19};

    std::string text = "AMYNORMALLYHATEDMONDAYMORNINGSBUTTHISYEARWASDIFFERENTKAMALWASINHERARTCLASSANDSHELIKEDKAMALSHEWASWAITINGOUTSIDETHECLASSROOMWHENHERFRIENDTARAARRIVEDHIAMYYOURMUMSENTMEATEXTYOUFORGOTYOURINHALERWHYDONTYOUTURNYOURPHONEONAMYDIDNTLIKETECHNOLOGYSHENEVERSENTTEXTMESSAGESANDSHEHATEDFACEBOOKTOODIDKAMALASKYOUTOTHEDISCOTARAWASAMYSBESTFRIENDANDSHEWANTEDTOKNOWEVERYTHINGTHATWASHAPPENINGINAMYSLIFEIDONTTHINKHELIKESMESAIDAMYANDINEVERSEEHIMALONEHESALWAYSWITHGRANTAMYANDTARADIDNTLIKEGRANTDOYOUKNOWABOUTTHEIRARTPROJECTASKEDAMYITSABOUTGRAFFITIITHINKSAIDTARATHEYREWORKINGONITATTHEOLDHOUSEBEHINDTHEFACTORYBUTTHATBUILDINGISDANGEROUSSAIDAMYAAHAREYOUWORRIEDHESGOINGTOGETHURTTARATEASEDSHUTUPTARAHEYLOOKHERETHEYCOMEKAMALANDGRANTARRIVEDHIKAMALSAIDTARAAREYOUGOINGTOTHEHALLOWEENDISCOTOMORROWYESHIAMYKAMALSAIDSMILINGDOYOUWANTTOCOMEANDSEEOURPAINTINGSAFTERSCHOOLIMCOMINGTOOTARAINSISTEDAFTERSCHOOLKAMALTOOKTHEGIRLSTOTHEOLDHOUSEITWASVERYOLDANDVERYDIRTYTOOTHEREWASRUBBISHEVERYWHERETHEWINDOWSWEREBROKENANDTHEWALLSWEREDAMPITWASSCARYAMYDIDNTLIKEITTHEREWEREPAINTINGSOFZOMBIESANDSKELETONSONTHEWALLSWEREGOINGTOTAKEPHOTOSFORTHESCHOOLARTCOMPETITIONSAIDKAMALAMYDIDNTLIKEITBUTSHEDIDNTSAYANYTHINGWHERESGRANTASKEDTARAERHESBUYINGMOREPAINTKAMALLOOKEDAWAYQUICKLYTARATHOUGHTHELOOKEDSUSPICIOUSITSGETTINGDARKCANWEGONOWSAIDAMYSHEDIDNTLIKEZOMBIESTHENTHEYHEARDALOUDNOISECOMINGFROMACUPBOARDINTHECORNEROFTHEROOMWHATSTHATAMYWASFRIGHTENEDIDIDNTHEARANYTHINGSAIDKAMALSOMETHINGWASMAKINGSTRANGENOISESTHEREWASSOMETHINGINSIDETHECUPBOARDOHNOWHATISITAMYWASVERYFRIGHTENEDNOWWHATDOYOUMEANTHERESNOTHINGTHEREKAMALWASTRYINGNOTTOSMILESUDDENLYTHEDOOROPENEDWITHABANGANDAZOMBIEAPPEAREDSHOUTINGANDMOVINGITSARMSAMYSCREAMEDANDCOVEREDHEREYESOHVERYFUNNYGRANTSAIDTARALOOKINGBOREDKAMALANDGRANTSTARTEDLAUGHINGHAHAYOUWEREFRIGHTENEDSAIDGRANTDOYOULIKEMYZOMBIECOSTUMEAMYTOOKTARASARMICANTBREATHESHESAIDKAMALLOOKEDWORRIEDNOWISSHEOKITWASONLYAJOKENOSHESNOTOKYOUIDIOTSHESHAVINGANASTHMAATTACKANDSHEFORGOTHERINHALERTARATOOKOUTHERPHONEIMCALLINGHERDADNEXTEVENINGWASHALLOWEENTHEGIRLSWEREATTHESCHOOLDISCOAREYOUBETTERNOWASKEDTARAIMFINESAIDAMYITHINKITWASTHESMELLOFPAINTTHATSTARTEDTHEATTACKTARALOOKEDAROUNDSOWHEREARETHEZOMBIESIDONTKNOWIDONTWANTTOSEEKAMALAGAINSAIDAMYCOMEONLETSDANCEAMYANDTARAWEREDANCINGWHENGRANTARRIVEDLOOKINGWORRIEDHISOMEONESTOLEMYPHONEHAVEYOUSEENKAMALHESAIDHEWASCOMINGHEREATEIGHTOCLOCKCANYOUPHONEHIMGOAWAYIDIOTTARADIDNTSTOPDANCINGGRANTLOOKEDUPSETTELLHIMIMLOOKINGFORHIMHECALLEDASHELEFTTHEDISCOTARAREALLYDIDNTLIKEGRANTJUSTTHENTARASPHONERANGSHELOOKEDATITHASHESAIDIDONTBELIEVEITWHATISITASKEDAMYKAMALJUSTSENTATEXTTOEVERYONELISTENTARAREADOUTKAMALSMESSAGEIMATTHEHOUSEICANTMOVEPLEASECALLANAMBULANCEMYBATTERYISRUNNINGOUTTHEGIRLSDIDNTSTOPDANCINGLOTSOFTHEIRFRIENDSSAWKAMALSMESSAGETOOBUTTARATOLDEVERYONEITWASJUSTAJOKETHEYALLIGNOREDITTHENEXTMORNINGAMYSMUMANDDADWERELISTENINGTOTHERADIOISAMYUPYETDADASKEDNOSHESTIREDSAIDMUMTURNINGTHEVOLUMEUPONTHERADIOTHISMORNINGPOLICEAREINVESTIGATINGTHEDEATHOFASIXTEENYEAROLDBOYHEDIEDLASTNIGHTINADISUSEDHOUSEONMOORTOWNROADDADPUTDOWNHISNEWSPAPERBUTTHATSWHEREAMYWENTWITHHERFRIENDSTHEYFOUNDTHEBODYEARLYTHISMORNINGHISNAMEWASKAMALNASEERBRENDANDUNNE";
    std::string res;

    std::vector<int> numbers_vector;
    std::vector<int> new_numbers;

    std::string new_text;

    letters_to_numbers(text, numbers_vector);
    numbers_to_letters(new_text, numbers_vector);

//    for (int i : numbers_vector) {
//        std::cout << i ;
//    }
//    std::cout << std::endl;

    std::cout << new_text << std::endl;
    new_text.clear();

    auto start = get_current_time_fenced();

    // _____________________________ for letter loop _____________________________
    for (auto letter: numbers_vector) {

        rotor1_position += 1;
        rotor1_position %= 26;

#ifdef DEBOUT
        std::cout << (char)(rotor3_position + 'A') << (char)(rotor2_position + 'A') <<  (char)(rotor1_position + 'A') << std::endl;
        std::cout << "old: " << letter << " " << (char)(letter + 'A') << std::endl;
#endif
        // _____________________________ apply plugboard: _____________________________
        letter = plugboard[letter];

#ifdef DEBOUT
        std::cout << "plugboard: " << letter << " " << (char)(letter + 'A') << std::endl;
#endif
        // _____________________________ apply rotor1: _____________________________
        letter = (rotor1_forward[(letter + rotor1_position)%26] - rotor1_position + 26) % 26 ;
        if (rotor1_position % 26 == rotor1_rotation) {
            rotor2_position += 1;
            rotor2_position %= 26;
        }
#ifdef DEBOUT
        std::cout << "rotor1: " << letter << " " << (char)(letter + 'A') << std::endl;
#endif
        // _____________________________ apply rotor2: _____________________________
        letter = (rotor2_forward[(letter + rotor2_position)%26] - rotor2_position + 26) % 26;
        if (rotor2_position % 26 == rotor2_rotation) {
            rotor3_position += 1;
            rotor3_position %= 26;
        }
#ifdef DEBOUT
        std::cout << "rotor2: " << letter << " " << (char)(letter + 'A') << std::endl;
#endif
        // _____________________________ apply rotor3: _____________________________
        letter = (rotor3_forward[(letter + rotor3_position)%26] - rotor3_position + 26) % 26;
#ifdef DEBOUT
        std::cout << "rotor3: " << letter << " " << (char)(letter + 'A') << std::endl;
#endif
        // _____________________________ apply reflector: _____________________________
        letter = reflector_UKV_B[letter];
#ifdef DEBOUT
        std::cout << "reflector: " << letter << " " << (char)(letter + 'A') << std::endl;
#endif
        // _____________________________ apply rotor3: _____________________________
        letter = (rotor3_backward[(letter + rotor3_position)%26] - rotor3_position + 26) % 26;
#ifdef DEBOUT
        std::cout << "rotor3: " << letter << " " << (char)(letter + 'A') << std::endl;
#endif
        // _____________________________ apply rotor2: _____________________________
        letter = (rotor2_backward[(letter + rotor2_position)%26] - rotor2_position + 26) % 26;
#ifdef DEBOUT
        std::cout << "rotor2: " << letter << " " << (char)(letter + 'A') << std::endl;
#endif
        // _____________________________ apply rotor1: _____________________________
        letter = (rotor1_backward[(letter + rotor1_position)%26] - rotor1_position + 26) % 26;
#ifdef DEBOUT
        std::cout << "rotor1: " << letter << " " << (char)(letter + 'A') << std::endl;
#endif
        // _____________________________ apply plugboard: _____________________________
        letter = plugboard[letter];


        new_numbers.emplace_back(letter);
#ifdef DEBOUT
        std::cout << "new: " << letter << " " << (char)(letter + 'A') << std::endl;
        std::cout << std::endl;
#endif
    }

    auto end = get_current_time_fenced();

    std::cout << std::endl;

    numbers_to_letters(new_text, new_numbers);

    std::cout << new_text << std::endl;

    std::cout << "time: " << to_seconds(end - start) << std::endl;



    return 0;
}
