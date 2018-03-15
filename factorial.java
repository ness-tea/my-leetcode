public class factorial {
    public static int factorial(int num) {
        int result;
        if (num == 1) {
            result = 1;
        }
        else {
            result = num*factorial(num-1);
        }
        return result;
    }
}