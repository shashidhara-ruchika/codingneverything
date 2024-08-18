import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

/*
 * Optimizing TikTok Collectible Packs

Byunca has launched awfattee on Talled Tak Collectives" where users can robest and trade gital carts featuring popular Tiktok creators. Fach cinator has different categories of sants, such as rare cards Tur the thet, spastal edition cards with sumque deugns, and inuractive cards that come with

Русалок ишль τη create a number of collect ble packs, euch containing soual numbe Te actieve this, thay deest sa add more cants to bers of each types of sans enture each type can be evenly doth istited crass the pack Given the current anventory of wach category of sands as art integer array cam/Types of size determine the Promum member of additional cards needed so that they can create more than one pack with an equal type attution

Example

carpes 47.512.153

In order to euke 2 matching packers, the following numbers of additional cards of sach type must be added: (0 11177 This sums to Cadditional sands. The numbers of cards are 4 & 6. 12. 16 and they can be divided senly arborg 2 packets if packets are created an additional/2211, Olcards are needed, surelems This yields quarries 1696 12, 15 Any number of packers a 2 can be croated, but wating 2 packets rocpares The minimun mariber of aciditional cards

Function Description

Complete the function card Packets in the editur halow

randPackets has the following parameters int cardtypespent the quemmry available of cards type

Returns

int the minimum number of additional cards to add.
 */

class Result {

    /*
     * Complete the 'cardPackets' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts INTEGER_ARRAY cardTypes as parameter.
     */

    public static int cardPackets(List<Integer> cardTypes) {
        
        int div = Collections.min(cardTypes);
        int count = 0;
        if (div != 1) {
            for (int c : cardTypes) {
                if (c % div == 0) {
                    count++;
                }
            }
            if (count == cardTypes.size()) {
                return 0;
            }
        }
    
        int s2 = 0;
        int s3 = 0;
        for (int c : cardTypes) {
            if (c % 2 != 0) {
                int x = (2 * (c / 2 + 1) ) - c;
                s2 += x;
            }
            if (c % 3 != 0) {
                int y = (3 * (c / 3 + 1)) - c;
                s3 += y;
            }
        }
        
        return Math.min(s2, s3);

    }

}

public class CardPackets {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int cardTypesCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> cardTypes = IntStream.range(0, cardTypesCount).mapToObj(i -> {
            try {
                return bufferedReader.readLine().replaceAll("\\s+$", "");
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
            .map(String::trim)
            .map(Integer::parseInt)
            .collect(toList());

        int result = Result.cardPackets(cardTypes);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
