import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;

public class Main {
  public static void main(String[] args) throws IOException {
    InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
    BufferedReader in = new BufferedReader(reader);

    Double amount, rate, down_pay, monthly_payment;
    Integer year, no_of_months, total_interest;
    String line, result;

    while ((line = in.readLine()) != null) {
      String[] input = line.split("~");

      amount = Double.valueOf(input[0]);
      year = Integer.valueOf(input[1]);
      rate = Double.valueOf(input[2]);
      down_pay = Double.valueOf(input[3]);

      amount = amount - down_pay;
      no_of_months = year*12;
      rate = rate/100;

      monthly_payment = calc_monthly_payment(amount, rate, no_of_months);
      total_interest = get_total_interest(monthly_payment, amount, no_of_months);

      result = get_result(monthly_payment, total_interest);
      System.out.println(result);
    }
  }

  static Double calc_monthly_payment(Double amount, Double rate, Integer n) {
      Double mir = rate/12; // monthly interest rate
      Double monthly_payment = (mir * amount) / (1 - Math.pow((1 + mir),-n));
      return round_2(monthly_payment);
  }

  static Double round_2(Double value) {
      return Math.round(value * 100.0) / 100.0;
  }

  static Integer get_total_interest(Double monthly_payment, Double amount, Integer no_of_months) {
      return Math.toIntExact(Math.round(monthly_payment * no_of_months - amount));
  }

  static String get_result(Double monthly_payment, Integer total_interest) {
      return "$" + Double.toString(monthly_payment) + "~$" + Integer.toString(total_interest);
  }
}
