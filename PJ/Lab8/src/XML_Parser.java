import javax.swing.*;
import javax.swing.Timer;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.io.IOException;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTree;
import javax.swing.tree.*;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.w3c.dom.*;
import org.xml.sax.SAXException;

public class XML_Parser extends JFrame {

    DefaultTreeModel dtModel = null;
    private JButton openXMLButton;
    private JTree DOMTree;
    private JPanel mainPane;
    private JLabel clock;
    DateFormat df = new SimpleDateFormat("HH:mm:ss");

    public void setPath(String filePath) {
        Node root = null;
        try {
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = factory.newDocumentBuilder();
            Document doc = builder.parse(filePath);
            root = (Node) doc.getDocumentElement();
        } catch (IOException | ParserConfigurationException | SAXException ex) {
            JOptionPane.showMessageDialog(null, "Can't parse file",
                    "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }
        if (root != null) {
            dtModel = new DefaultTreeModel(builtTreeNode(root));
            DOMTree.setModel(dtModel);
        }
    }

    private DefaultMutableTreeNode builtTreeNode(Node root) {
        DefaultMutableTreeNode dmtNode;

        dmtNode = new DefaultMutableTreeNode(root.getNodeName());
        NodeList nodeList = root.getChildNodes();
        for (int count = 0; count < nodeList.getLength(); count++) {
            Node tempNode = nodeList.item(count);
            if (tempNode.getNodeType() == Node.ELEMENT_NODE) {
                dmtNode.add(builtTreeNode(tempNode));
            } else if(tempNode.getNodeType() == Node.TEXT_NODE && tempNode.getTextContent().trim().length() > 0) {
                dmtNode.add(new DefaultMutableTreeNode(tempNode.getTextContent()));
            }
        }
        return dmtNode;
    }


    public XML_Parser(String title) {
        super(title);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setContentPane(mainPane);
        this.setSize(600, 500);
        this.setResizable(false);
        this.pack();


        Timer timer = new javax.swing.Timer(1000, new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                clock.setText(df.format(new Date()));
            }
        });
        timer.start();

        DOMTree.setModel(null);
        openXMLButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                File workingDirectory = new File(System.getProperty("user.dir"));
                JFileChooser jfc = new JFileChooser(workingDirectory);
                FileNameExtensionFilter filter = new FileNameExtensionFilter("XML files", "XML", "xml");
                jfc.setFileFilter(filter);

                int returnValue = jfc.showOpenDialog(null);
                if (returnValue == JFileChooser.APPROVE_OPTION) {
                    File selectedFile = jfc.getSelectedFile();
                    setPath(((File) selectedFile).getAbsolutePath());
                }
            }
        });
    }

    public static void main(String[] args) {
        JFrame frame = new XML_Parser("XML Parser");
        frame.setVisible(true);
    }
}
