public class BoundedBufferTester extends BoundedBuffer {
   /**
   * the main method which calls all of the test methods in the class
   * @param args String[] array containing command line parameters
   * @return void
   */
   public static void main ( String [] args ) throws Exception {
      test_insert();              // 1 tests
      test_retrieve();            // 3 tests
   }
     
    /**
     * test method to test out the operation of the insert method from BoundedBuffer
     */
   public static void  test_insert() {
      BoundedBuffer oofTesterOne = new BoundedBuffer();
      Object o = new Object();
      System.out.println( "\n3 TESTS FOR insert():" );
      try { 
         oofTesterOne.insert(o);
         System.out.println("Object Inserted");
      }
      catch( Exception e ) { System.out.println ( "Exception: " + e ); }
   }
  
    /**
     * test method to test out the operation of the retrieve method from BoundedBuffer
     */
   public static void test_retrieve() {
      BoundedBuffer oofTesterOne = new BoundedBuffer();
      Object z = new Object();
      try { 
         oofTesterOne.insert(z);
         oofTesterOne.retrieve();
         System.out.println("Object Retrieved");
      }
      catch( Exception e ) { System.out.println ( "Exception: " + e ); }
   }
}