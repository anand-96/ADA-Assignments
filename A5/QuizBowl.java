import java.io.FileInputStream;
import java.util.Random;
import java.util.Scanner;

class Participant
{
    private String firstName;
    private String lastName;
    private int score;

    public String getFirstName() 
    {
        return firstName;
    }

    public String getLastName() 
    {
        return lastName;
    }

    public int getScore() 
    {
        return score;
    }

    public void setFirstName(String firstName) 
    {
        this.firstName = firstName;
    }

    public void setLastName(String lastName) 
    {
        this.lastName = lastName;
    }

    public void setScore(int score) 
    {
        this.score = score;
    }   
}

abstract class Question
{
   private String question;
   private int points;
   private String answer;
   public int count;
    public String getAnswer() {
        return answer;
    }

    public void setAnswer(String answer) {
        this.answer = answer;
    }
   
   public String getQuestion() 
   {
        return question;
   }
   public int getPoints() 
   {
        return points;
   }
   public void setQuestion(String question) 
   {
        this.question = question;
   }
   public void setPoints(int points) 
   {
        this.points = points;
   }
   
   abstract public void read(FileInputStream fin, Participant p);
}
class QuestionTF extends Question
{
    public void read(FileInputStream fin, Participant p) 
    {
        try 
        {
            int x=0;
            char c='a';
            String temp="";
            while(true)
            {
               x=fin.read();
               c = (char)x;
               if(c=='\n')
                   break;
               temp = temp+""+c;
            }
            temp = temp.trim();
            setPoints(Integer.parseInt(temp));
            temp="";
            x=fin.read();
            c=(char)x;
            while(c!='\n'&&x>0)
            {
                temp=temp+""+c;
                x = fin.read();
                c=(char)x;
            }
            temp = temp.trim();
            setQuestion(temp);
            temp="";
            x=fin.read();
            c=(char)x;
            while(c!='\n'&&x>0)
            {
                temp=temp+""+c;
                x = fin.read();
                c=(char)x;
            }
            temp = temp.trim();
            setAnswer(temp);
        } 
        catch (Exception e) 
        {
            System.err.println(""+e);
        }
    }
    public void check() 
    {
 
    }
}
class QuestionMC extends Question
{

    public void read(FileInputStream fin, Participant p) 
    {
        try 
        {
            int x=0;
            char c='a';
            String temp="";
            while(true)
            {
               x=fin.read();
               c = (char)x;
               if(c=='\n')
                   break;
               temp = temp+""+c;
            }
            temp = temp.trim();
            setPoints(Integer.parseInt(temp));
            temp="";
            x=fin.read();
            c=(char)x;
            while(c!='\n')
            {
                temp=temp+""+c;
                x = fin.read();
                c=(char)x;
            }
            temp = temp.trim();
            setQuestion(temp);
            temp="";
            x=fin.read();
            c=(char)x;
            while(c!='\n'&&x>0)
            {
                temp=temp+""+c;
                x = fin.read();
                c=(char)x;
            }
            temp = temp.trim();
            String option="";
            int n = Integer.parseInt(temp);
            for(int i=0;i<n;i++)
            {
                temp="";
                x=fin.read();
                c=(char)x;
                while(c!='\n'&&x>0)
                {
                    temp=temp+""+c;
                    x = fin.read();
                    c=(char)x;
                }
                option =  option+"\n("+(char)(65+i) +") "+ temp;
            }
            //System.out.println(getQuestion()+""+option);
            setQuestion(getQuestion()+""+option+"\n");
            temp="";
            x=fin.read();
            c=(char)x;
            while(c!='\n'&&x>0)
            {
                temp=temp+""+c;
                x = fin.read();
                c=(char)x;
            }
            temp = temp.trim();
            setAnswer(temp);
        } 
        catch (Exception e) 
        {
            System.err.println(""+e);
        }
    }
    public void check() 
    {
 
    }
    
}
class QuestionSA extends Question
{
    public void read(FileInputStream fin, Participant p) 
    {
        try 
        {
            int x=0;
            char c='a';
            String temp="";
            while(true)
            {
               x=fin.read();
               c = (char)x;
               if(c=='\n')
                   break;
               temp = temp+""+c;
            }
            temp = temp.trim();
            setPoints(Integer.parseInt(temp));
            temp="";
            x=fin.read();
            c=(char)x;
            while(c!='\n')
            {
                temp=temp+""+c;
                x = fin.read();
                c=(char)x;
            }
            temp = temp.trim();
            setQuestion(temp);
            temp="";
            x=fin.read();
            c=(char)x;
            while(c!='\n'&&x>0)
            {
                temp=temp+""+c;
                x = fin.read();
                c=(char)x;
            }
            temp = temp.trim();
            setAnswer(temp);
        } 
        catch (Exception e) 
        {
            System.err.println(""+e);
        }
    }
    public void check() 
    {
      
    }
}
class QuizBowl
{
   public static void main(String args[])
   {
       try 
       {
           Participant p = new Participant();
           System.out.println("What is your first name?");
           Scanner scan= new Scanner(System.in);
           p.setFirstName(scan.next());
           System.out.println("What is your last name?");
           p.setLastName(scan.next());
           System.out.println("What files stores your Questions?");
           String file= scan.next();
           FileInputStream fin = new FileInputStream("C:\\Users\\HP-PC\\Desktop\\A5\\"+file);
           int x=0;
           String nQue="";
           try {
            while(true)
           {
               x=fin.read();
               if((char)x=='\n')
                   break;
               char c = (char)x;
               System.out.print(c);
               nQue= nQue+""+c;
           }   
           } catch (Exception e) {
               System.err.println(""+e);
           }
           nQue= nQue.trim();
           int n = Integer.parseInt(nQue);
           int queN=0;
           //System.out.println("HELLLEOO");
           while(true)
           {
               try 
               {
                  System.err.println("How Many questions whould you like to (out of "+n+")");
                  queN=scan.nextInt();
                  if(queN>n)
                  {
                      System.out.println("Sorry, thats too many!!");
                      queN=0;
                  }
                  else if(queN<=0)
                  {
                      System.out.println("Sorry, not zero atleast or negative!!");
                      queN=0;
                  }
                  else
                  {
                      break;
                  }
                }
                catch (Exception e) 
                {
                    System.out.println("Sorry, That is not valid");
                    break;
                }
           }
           Question que[] = new Question[Integer.parseInt(nQue)];
           int i=0;
           int k=1;
           while(x>=0)
           {
               x= fin.read();
               String qType = ""+(char)x+""+(char)fin.read()+""+(char)fin.read();
               if(qType.equals("MC "))
               {
                   que[i++]= new QuestionMC();
                   que[i-1].read(fin, p);
               }
               else if(qType.equals("TF "))
               {
                   que[i++]= new QuestionTF();
                   que[i-1].read(fin, p);
               }
               else if(qType.equals("SA "))
               {
                   que[i++]= new QuestionSA();
                   que[i-1].read(fin, p);
               }
               k++;
           }
           for(int j=0;j<queN;j++)
           {
               Random r=new Random();
               int randomCount = r.nextInt(n);
               if(que[randomCount].count==0)
               {
                System.out.println("Point :- "+ que[randomCount].getPoints());
                System.out.println("Question :- "+que[randomCount].getQuestion());
                String reply=scan.next();
                String temp = que[randomCount].getAnswer();
                if(reply.equals(temp))
                 {
                     System.out.println("Correct ! You get "+que[randomCount].getPoints()+" points");
                     p.setScore(que[randomCount].getPoints()+p.getScore());
                 }
                 else if(reply.toLowerCase().equals("skip"))
                 {
                     System.out.println("Okay! You Can Skip this question");
                     p.setScore(p.getScore()+0);
                 }
                 else
                 {
                     System.out.println("InCorrect ! You lost "+que[randomCount].getPoints()+" points");
                     p.setScore(p.getScore()-que[randomCount].getPoints());
                 }
                que[randomCount].count=1;
               }
               else
               {
                   j--;
               }
              }
           System.out.println(p.getFirstName()+" "+p.getLastName()+", your game is over!");
           System.out.println("Your final Score is "+p.getScore()+" points.");
           System.out.println("Better Luck next time!");
       }
        catch(Exception e)
        {
           
        }
    }
}