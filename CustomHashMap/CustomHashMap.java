package CustomHashMap;

public class CustomHashMap<K, V> {

    private static final int initial_size = 16;
    private int table_size = 16;
    private static final float load_factory = 0.75f;
    private int entries_count = 0;
    private Node[] table;

    int get_size(){
        return entries_count;
    }
    int capacity(){
        return table_size;
    }

    static final int hash(Object key) {
        int h;
        return (key == null) ? 0 : (h = key.hashCode()) ^ (h >>> 16);
    }

    public void put(K key, V value){
        if(entries_count == 0 )
            this.table = new Node[initial_size];

        int i = (table_size - 1) & hash(key);
        int hash = hash(key);

        if(table[i] == null) {
            table[i] = new Node<K,V>(hash(key), key, value);
            ++ entries_count;
        }
        else{
            Node<K,V> current = table[i];

            do {
                {
                    if(key == current.key && current.hash == hash){
                        current.value = value;
                        break;
                    }
                    else if(current.next == null){
                        current.next = new Node<K,V>(hash(key), key, value);
                        ++ entries_count;
                        break;
                    }
                    else{
                        current = current.next;
                    }
                }
            }
            while(current != null);
        }

        if(entries_count >= load_factory * table_size){
            resize();
        }
    }

    public Object get(K key){
        if(table != null) {

            int i = (table_size - 1) & hash(key);
            int hash = hash(key);
            Node<K, V> current = table[i];

            if (table[i] != null) {
                do {
                    if (table[i].hash == hash && (table[i].key == key || table[i].key.equals(key))) {
                        return table[i].value;
                    } else if (current.next != null) {
                        current = current.next;
                        if (current.hash == hash && (current.key == key || current.key.equals(key))) {
                            return current.value;
                        }
                    }
                }
                while (current.next != null);
            }
        }

        return null;

    }

    public Object remove(K key){
        if(table != null) {

            int i = (table_size - 1) & hash(key);
            int hash = hash(key);
            Node<K, V> current = table[i];

            if (table[i] != null) {
                do {
                    if (table[i].hash == hash && (table[i].key == key || table[i].key.equals(key))) {
                        if (table[i].next == null) {
                            Object v = table[i].value;
                            table[i] = null;
                            --entries_count;
                            return v;
                        } else {
                            Object v = table[i].value;
                            table[i] = table[i].next;
                            --entries_count;
                            return v;
                        }
                    } else if (current.next != null) {
                        Node<K, V> prev = current;
                        current = current.next;
                        if (current.hash == hash && (current.key == key || current.key.equals(key))) {
                            Object v = current.value;
                            prev.next = current.next;
                            --entries_count;
                            return v;
                        }
                    }
                }
                while (current.next != null);
            }
        }

        return null;
    }

    @Override
    public String toString(){
        String str = "{";
        if(table != null) {

            for (int i = 0; i < table_size; ++i) {
                if (table[i] != null) {
                    str += table[i].key;
                    str += "=";
                    str += table[i].value;
                    str += ", ";

                }
                if (table[i] != null && table[i].next != null) {
                    Node<K, V> current = table[i];

                    do {
                        current = current.next;
                        str += current.key;
                        str += "=";
                        str += current.value;
                        str += ", ";
                    }
                    while (current.next != null);
                }
            }
            str = str.substring(0,str.length()-2);
        }

        str += "}";

        return str;
    }

    private void resize(){
        Node[] array = table;
        int array_size = table_size;
        table_size = 2*table_size;

        table = new Node[2*table_size];

        for (int i = 0; i < array_size; ++i) {
            if (array[i] != null) {
                K k = (K) array[i].key;
                V v = (V) array[i].value;

                put(k,v);

            }
            if (array[i] != null && array[i].next != null) {
                Node<K, V> current = array[i];

                do {
                    current = current.next;
                    K k = (K) current.key;
                    V v = (V) current.value;
                    put(k,v);

                }
                while (current.next != null);
            }
        }
        array = null;
    }


    private class Node<K, V>{
        int hash;
        K key;
        V value;
        Node<K, V> next = null;

        Node(int hash, K key, V value){
            this.hash = hash;
            this.key = key;
            this.value = value;
        }

    }
}
