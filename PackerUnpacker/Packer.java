import java.io.*;
import java.util.*;

class PackerX
{
    public String Header;

    public byte Key;

    public int iRet;
    public int i;
    public int j;

    public byte Buffer[];
    public byte bHeader[];

    public File fArr[];

    public File fobj;
    File PackObj;
    public FileInputStream fiobj;
    public FileOutputStream foobj;

    Scanner sobj;

    public PackerX()
    {
        this.Header = null;

        this.Key = 0x11;

        this.iRet = 0;
        this.i = 0;
        this.j = 0;

        this.Buffer = new byte[1024];
        this.bHeader = new byte[100];

        this.fArr = null;

        this.fobj = null;
        this.PackObj = null;
        this.fiobj = null;
        this.foobj = null;

        this.sobj = null;
    }

    protected void Finalized()
    {
        try
        {
            fiobj.close();
            foobj.close();
        }
        catch(IOException aobj)
        {
            System.out.println(aobj);
        }
        PackObj = null;
        fobj = null;
        sobj.close();
    }

    public void packing()
    {
        sobj = new Scanner(System.in);

        System.out.println("Enter the name of folder : ");
        String FolderName = sobj.nextLine();

        System.out.println("Enter the name of packed file : ");
        String PackName = sobj.nextLine();

        System.out.println("Enter the type of file :(.java,.c,.cpp,.txt)");
        String FileExtension = sobj.nextLine();

        fobj = new File(FolderName);

        try
        {
            if((fobj.exists()) && (fobj.isDirectory()))
            {
                PackObj = new File(PackName);

                PackObj.createNewFile();

                foobj = new FileOutputStream(PackObj);
                
                System.out.println("Folder is present");

                fArr = fobj.listFiles();
                
                System.out.println("Number of files in the folder are : "+fArr.length);

                for(i = 0; i < fArr.length; i++)
                {
                    fiobj = new FileInputStream(fArr[i]);

                    if(fArr[i].getName().endsWith(FileExtension))
                    {
                        // Header Formation
                        Header = fArr[i].getName() + " " + fArr[i].length();
                        for(j = Header.length(); j < 100; j++)
                        {
                            Header = Header + " ";
                        }

                        bHeader = Header.getBytes();
                        
                        //Write header into pack file
                        foobj.write(bHeader,0,100);

                        // Read the data from input files from Marvellous folder
                        while((iRet = fiobj.read(Buffer)) != -1)
                        {
                            // Encryption Logic
                            for(j = 0; j < iRet; j++)
                            {
                                Buffer[j] = (byte)(Buffer[j] ^ Key);
                            }

                            //Write the files data into Pack file
                            foobj.write(Buffer,0,iRet);
                        }
                    }
                }
            }
            else
            {
                System.out.println("There is no such folder");
            }
        }
        catch(IOException eobj)
        {
            System.out.println(eobj);
        }
    }
}


public class Packer
{
    public static void main(String A[])
    {
        PackerX pobj = new PackerX();

        pobj.packing();

    }
}