import java.io.*;
import java.util.Arrays;

public class MergeSort {

    public static int[] merge(int[] left, int[] right) {
        int[] merged = new int[left.length + right.length];
        int leftIndex = 0, rightIndex = 0, mergeIndex = 0;

        while (leftIndex < left.length && rightIndex < right.length) {
            if (left[leftIndex] <= right[rightIndex]) {
                merged[mergeIndex++] = left[leftIndex++];
            } else {
                merged[mergeIndex++] = right[rightIndex++];
            }
        }

        while (leftIndex < left.length) {
            merged[mergeIndex++] = left[leftIndex++];
        }

        while (rightIndex < right.length) {
            merged[mergeIndex++] = right[rightIndex++];
        }

        return merged;
    }

    public static int[] mergeSort(int[] data) {
        if (data.length <= 1) {
            return data;
        }

        int mid = data.length / 2;
        int[] left = Arrays.copyOfRange(data, 0, mid);
        int[] right = Arrays.copyOfRange(data, mid, data.length);

        left = mergeSort(left);
        right = mergeSort(right);

        return merge(left, right);
    }

    public static void main(String[] args) {
        if (args.length < 1 || args.length > 2) {
            System.out.println("Usage: java MergeSort <file> [write_output]");
            System.exit(1);
        }

        String filePath = args[0];
        boolean writeOutput = args.length == 2 && args[1].equals("true");

        if (!filePath.endsWith(".txt")) {
            System.out.println("File must be a .txt file");
            System.exit(1);
        }

        try {
            BufferedReader reader = new BufferedReader(new FileReader(filePath));
            reader.readLine(); // Skip first line
            String[] data = reader.readLine().split(";");
            int[] intData = new int[data.length];
            for (int i = 0; i < data.length; i++) {
                intData[i] = Integer.parseInt(data[i].trim());
            }
            reader.close();

            int[] sorted = mergeSort(intData);

            if (writeOutput) {
                BufferedWriter writer = new BufferedWriter(new FileWriter("result.txt"));
                writer.write(sorted.length + "\n");
                for (int i = 0; i < sorted.length; i++) {
                    writer.write(sorted[i] + (i < sorted.length - 1 ? ";" : ""));
                }
                writer.close();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
