public class CircularLinkedList{
    private Node first;
    private Node last;

    public boolean isEmpty(){
        return (first == null);
    }

    public void insertFirst(int data){
        Node newNode = new Node();
        newNode.data = data;
        if (isEmpty()){
            last = newNode;
        }
        newNode.next = first;
        first = newNode;
    }

    public int delete(){
        int temp = first.data;
        if (first.next == null){
            last = null;
        }
        first = first.next;
        return temp;
    }

    public void insertEnd(int data){
        Node newNode = new Node();
        newNode.data = data;
        if (isEmpty()){
            first = newNode;
        }else{
            last.next = newNode;
            last = newNode;
        }
    }

    public void displayList(){
        Node current = first;
        while (current != null){
            current.displayNode();
            current = current.next;
        }
    }

    public static void main(String[] args) {
        CircularLinkedList linkedList = new CircularLinkedList();
        linkedList.insertFirst(10);
        linkedList.insertFirst(20);
        linkedList.insertEnd(30);
        linkedList.displayList();
    }
}