import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Collections;

class Asset {
    public String name,type;
    public Double price, interest,shares;
    public static Double port_total, bench_total;

    static {
        port_total = 0.0;
        bench_total = 0.0;
    }

    public Asset (String name, String type, Double shares, Double price, Double interest) {
        this.name = name;
        this.type = type;
        this.shares = shares;
        this.price = price;
        this.interest = interest;
    }

    public Double get_market_price() {
        if(this.type.equals("STOCK")) {
            return shares * price;
        }
        else {
            return shares * (price + interest) * 0.01;
        }
    }

    public static void update_total(Asset asset, String type) {
        if (type.equals("Portfolio")) {
            port_total += asset.get_market_price();
        } else {
            bench_total += asset.get_market_price();
        }
    }

    public static void change(Asset p, Asset b) {
        Double diff = 0.0;
        if (p.type.equals("STOCK")) {
            diff = ((b.shares * b.price * port_total) / (p.price * bench_total)) - p.shares;
        } else {
            diff = ((b.shares * (b.price + b.interest)* port_total) / ((p.price + p.interest) * bench_total)) - p.shares;
        }

        Integer transaction = Math.toIntExact(Math.round(diff));
        if (transaction > 0) {
          System.out.println("BUY,"+p.name+","+Integer.toString(transaction));
        } else if (transaction < 0) {
          System.out.println("SELL,"+p.name+","+Integer.toString(-transaction));
        }
    }
}

class Sortbyname implements Comparator<Asset> {
    public int compare(Asset a, Asset b) {
        return a.name.compareTo(b.name);
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
        BufferedReader in = new BufferedReader(reader);
        String line;
        while ((line = in.readLine()) != null) {
            String[] input = line.split(":");
            String portfolio = input[0];
            String bench_mark = input[1];

            String[] port_arr = portfolio.split("\\|");
            ArrayList<Asset> port_list = new ArrayList<Asset>();
            for (String port : port_arr) {
                String arr[] = port.split(",");
                String name = arr[0];
                String type = arr[1];
                Double shares = Double.valueOf(arr[2]);
                Double price = Double.valueOf(arr[3]);
                Double interest = Double.valueOf(arr[4]);

                Asset asset = new Asset(name, type, shares, price, interest);
                port_list.add(asset);
                Asset.update_total(asset,"Portfolio");
            }

            String[] bench_arr = bench_mark.split("\\|");
            ArrayList<Asset> bench_list = new ArrayList<Asset>();
            for (String bench : bench_arr) {
                String arr[] = bench.split(",");
                String name = arr[0];
                String type = arr[1];
                Double shares = Double.valueOf(arr[2]);
                Double price = Double.valueOf(arr[3]);
                Double interest = Double.valueOf(arr[4]);

                Asset asset = new Asset(name, type, shares, price, interest);
                bench_list.add(asset);
                Asset.update_total(asset,"Benchmark");
            }

            Collections.sort(port_list,new Sortbyname());
            Collections.sort(bench_list,new Sortbyname());
            for (int i = 0; i < port_list.size(); i++) {
                Asset p = port_list.get(i);
                Asset b = bench_list.get(i);
                Asset.change(p,b);
            }
        } // end while loop
    }// end main
}
