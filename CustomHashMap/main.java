package CustomHashMap;

public class main {
    public static void main(String[] args) {

        CustomHashMap<String, Integer> str = new CustomHashMap<String, Integer>();



        //add elements
        str.put("Alex",7516);
        str.put("Jack",4578);
        str.put("Tom",548);
        str.put("John",142);
        str.put("Anna",789);
        str.put("Andrea",20);


        System.out.println("Size of CustomHashMap: " + str.get_size());
        System.out.println("Capacity of CustomHashMap: " + str.capacity());
        System.out.println();
        System.out.println("Elements in CustomHashMap");
        System.out.println(str);


        //remove elements

        System.out.println();
        System.out.println("Remove element");
        str.remove("Jack");

        System.out.println("Size of CustomHashMap: " + str.get_size());
        System.out.println();
        System.out.println("Elements in CustomHashMap");
        System.out.println(str);
        System.out.println();




        //getting value by key
        System.out.println("Getting value of Andrea");
        System.out.println(str.get("Andrea"));
        System.out.println();


        //remove elements
        System.out.println("Remove elements");
        str.remove("Jack");
        str.remove("Tom");
        str.remove("John");
        str.remove("Anna");
        str.remove("AAAAA");

        System.out.println("Size of CustomHashMap: " + str.get_size());
        System.out.println();
        System.out.println("Elements in CustomHashMap");
        System.out.println(str);

    }
}
