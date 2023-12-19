import java.awt.Button;
import java.awt.Frame;

class Window1 extends Frame {
    Window1() {
        System.out.println("constructor called");
        Button b = new Button("Click");
        add(b);
        b.setSize(80, 380);
        setLayout(null);
        // setSize(300, 300);
        setTitle("AWT program");
        setBounds(50, 50, 400, 1000);
        setVisible(true);
    }
    // public void WindowFunc(){
    //
    // }

}

public class AWT_Frame {
    public static void main(String[] args) {
        Window1 w = new Window1();
        // w.WindowFunc();
    }
}
