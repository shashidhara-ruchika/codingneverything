import java.io.*;
import java.util.*;
import java.util.stream.*;

import static java.util.stream.Collectors.toList;

class CalculateCatchMerchantFrauds {

    /*
     * Complete the 'find_fraudulent_merchants' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts following parameters:
     * 1. STRING non_fraud_codes
     * 2. STRING fraud_codes
     * 3. STRING_ARRAY mcc_thresholds
     * 4. STRING_ARRAY merchant_mcc_map
     * 5. STRING min_charges
     * 6. STRING_ARRAY charges
     */

    public static String find_fraudulent_merchants(String non_fraud_codes, String fraud_codes,
            List<String> mcc_thresholds, List<String> merchant_mcc_map, String min_charges, List<String> charges) {

        Double minCharges = Double.parseDouble(min_charges);

        Set<String> successCodes = Arrays.asList(non_fraud_codes.split(",")).stream()
                .map(s -> s.replace("\"", "")).collect(Collectors.toSet());
        Set<String> fraudCodes = Arrays.asList(fraud_codes.split(",")).stream()
                .map(s -> s.replace("\"", "")).collect(Collectors.toSet());

        Map<String, Double> mccThresholdMap = new HashMap<>();
        mcc_thresholds.forEach(s -> {
            String[] mccThresholdAction = s.split(",");
            String mcc = mccThresholdAction[0];
            Double threshold = Double.parseDouble(mccThresholdAction[1]);
            mccThresholdMap.put(mcc, threshold);
        });

        Map<String, String> merchantMccMap = new HashMap<>();
        Map<String, Double> merchantFraudCount = new HashMap<>();
        Map<String, Double> merchantTransactionCount = new HashMap<>();
        merchant_mcc_map.forEach(s -> {
            String[] merchantMccAction = s.split(",");
            String merchant = merchantMccAction[0];
            String mcc = merchantMccAction[1];
            merchantMccMap.put(merchant, mcc);
            merchantFraudCount.put(merchant, 0.0);
            merchantTransactionCount.put(merchant, 0.0);
        });

        Map<String, String> chargeNumberTransactionStringMap = new HashMap<>();

        charges.forEach(transactionString -> {
            String[] transactionAction = transactionString.split(",");
            String transactionType = transactionAction[0];
            if ("CHARGE".equals(transactionType)) {
                String chargeNumber = transactionAction[1];
                chargeNumberTransactionStringMap.put(chargeNumber, transactionString);

                String code = transactionAction[4];
                String merchant = transactionAction[2];

                Double count = merchantTransactionCount.get(merchant);
                merchantTransactionCount.put(merchant, count + 1.0);

                Double currentFraudCount = merchantFraudCount.get(merchant);
                if ((fraudCodes.contains(code) || !successCodes.contains(code)) && count > minCharges) {
                    merchantFraudCount.put(merchant, currentFraudCount + 1.0);
                }
            } else if ("DISPUTE".equals(transactionType)) {
                String chargeNumber = transactionAction[1];
                String chargeTransactionString = chargeNumberTransactionStringMap.get(chargeNumber);
                String[] chargeTransactionAction = chargeTransactionString.split(",");

                String code = chargeTransactionAction[4];
                String merchant = chargeTransactionAction[2];

                Double currentFraudCount = merchantFraudCount.get(merchant);
                if ((fraudCodes.contains(code) || !successCodes.contains(code)) && currentFraudCount >= 1.0) {
                    merchantFraudCount.put(merchant, currentFraudCount - 1.0);
                }
            }
        });

        List<String> merchants = new ArrayList<>();
        merchantFraudCount.forEach((merchant, fraudCount) -> {
            String mcc = merchantMccMap.get(merchant);
            Double threshold = mccThresholdMap.get(mcc);
            if (threshold >= 1) {
                if (fraudCount >= threshold) {
                    merchants.add(merchant);
                }
            } else if (threshold >= 0 && threshold < 1) {
                Double fraudRatio = fraudCount / merchantTransactionCount.get(merchant);
                if (fraudRatio >= threshold) {
                    merchants.add(merchant);
                }
            }
        });
        return String.join(",", merchants.stream().sorted().collect(Collectors.toList()));

    }

}

public class CatchMerchantFrauds {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String non_fraud_codes = bufferedReader.readLine();

        String fraud_codes = bufferedReader.readLine();

        int mcc_thresholdsCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<String> mcc_thresholds = IntStream.range(0, mcc_thresholdsCount).mapToObj(i -> {
            try {
                return bufferedReader.readLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
                .collect(toList());

        int merchant_mcc_mapCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<String> merchant_mcc_map = IntStream.range(0, merchant_mcc_mapCount).mapToObj(i -> {
            try {
                return bufferedReader.readLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
                .collect(toList());

        String min_charges = bufferedReader.readLine();

        int chargesCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<String> charges = IntStream.range(0, chargesCount).mapToObj(i -> {
            try {
                return bufferedReader.readLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
                .collect(toList());

        String result = CalculateCatchMerchantFrauds.find_fraudulent_merchants(non_fraud_codes, fraud_codes,
                mcc_thresholds, merchant_mcc_map, min_charges, charges);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
