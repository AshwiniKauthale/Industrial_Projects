
/////////////////////////////////////////////////////////////////////////////////
//
//      Packages Inclusion
//
/////////////////////////////////////////////////////////////////////////////////

import java.io.*;
import java.util.*;

////////////////////////////////////////////////////////////////////////////////
//
//      Helper Class
//
////////////////////////////////////////////////////////////////////////////////

class UnpackerX
{
        public int FileSize;
        public int i;
        public int iRet;

        public byte Key;

        public Scanner sobj;

        public String FileName;
        public String Header;
        public String Tokens[];

        public File fpackobj;
        public File fobj;
    
        public FileInputStream fiobj;
        public FileOutputStream foobj;
    
        public byte bHeader[];
        public byte Buffer[];

////////////////////////////////////////////////////////////////////////////////
//
//      Constructor of Helper Class
//
////////////////////////////////////////////////////////////////////////////////

    public UnpackerX()
    {
        this.FileSize = 0;
        this.i = 0;
        this.iRet = 0;

        this.Key = 0x11;

        this.sobj = null;
        this.FileName = null;
        this.Header = null;
        this.Tokens = null;

        this.fpackobj = null;
        this.fobj = null;
    
        this.fiobj = null;
        this.foobj = null;
    
        this.bHeader = new byte[100];
        this.Buffer = null;
    }

///////////////////////////////////////////////////////////////////////////////
//
//      Function Name :  Finalized()
//      Description :    It is used to dellocate the resources allocated inside the Constructor
//      Input :          Nothing
//      Output:          Nothing
//      Author :         Ashwini Vishnu Kauthale
//      Data :           31/01/2026
//
///////////////////////////////////////////////////////////////////////////////

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
        fpackobj = null;
        fobj = null;
        sobj.close();
    }

///////////////////////////////////////////////////////////////////////////////
//
//      Function Name :  Unacking
//      Description :    It is used to unpack files from packed file
//      Input :          Nothing
//      Output:          Nothing
//      Author :         Ashwini Vishnu Kauthale
//      Data :           31/01/2026
//
///////////////////////////////////////////////////////////////////////////////

    public void Unpacking()
    {
        sobj = new Scanner(System.in);

        System.out.println("Enter the name of packed file");
        FileName = sobj.nextLine();

        fpackobj = new File(FileName);

        if(fpackobj.exists() == false)
        {
            System.out.println("Error : There is no such packer file");
            return;
        }
        
        try
        {
            fiobj = new FileInputStream(fpackobj);

            // Read the Header
            while((iRet = fiobj.read(bHeader,0,100)) != -1)
            {
                Header = new String(bHeader);

                Header = Header.trim();

                Tokens = Header.split(" ");

                System.out.println("File name : "+Tokens[0]);
                System.out.println("File size : "+Tokens[1]);

                fobj = new File(Tokens[0]);

                fobj.createNewFile();

                foobj = new FileOutputStream((fobj));

                FileSize = Integer.parseInt(Tokens[1]);

                // Buffer for reading the data
                Buffer = new byte[FileSize];

                // Read from packed file
                fiobj.read(Buffer,0,FileSize);

                // Decrypte the data
                for(i = 0; i < FileSize; i++)
                {
                    Buffer[i] = (byte)(Buffer[i] ^ Key);
                }
                // Write into extracted file
                foobj.write(Buffer,0,FileSize);
            }
        }
        catch(IOException aobj)
        {
            System.out.println(aobj);
        }
        catch(NumberFormatException eobj)
        {
            System.out.println(eobj);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//      Main Class
//
////////////////////////////////////////////////////////////////////////////////

class Unpacker
{
    public static void main(String A[])
    {

        ///////////////////////////////////////////////////////////////////////////////
//
//      Entry Point Function of this class
//
///////////////////////////////////////////////////////////////////////////////

        UnpackerX uobj = new UnpackerX();

        uobj.Unpacking();

    }
}
