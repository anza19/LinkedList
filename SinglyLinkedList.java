public class SinglyLinkedList{
    private Node first;

    public boolean isEmpty(){
        return (first == null);
    }

    public void insertFirst(int data){
        Node newNode = new Node();
        newNode.data = data;
        newNode.next = first;
        first =  newNode;
    }

    public Node deleteFirst(){
        Node temp = first;
        first = first.next;
        return temp;
    }

    public void insertEnd(int data){
        Node current = first;
        while (current.next != null){
            current = current.next;
        }
        Node newNode = new Node();
        newNode.data = data;
        current.next = newNode;
    }

    public int lengthList(){
        int length = 0;
        Node current = first;
        while (current != null){
            length++;
            current = current.next;
        }
        return length;
    }

    public void  displayList(){
        Node current = first;
        while (current != null){
            current.displayNode();
            current = current.next;
        }
    }
}