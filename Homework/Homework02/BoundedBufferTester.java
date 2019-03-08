public class BoundedBufferTester {
    /**
     * the main method which calls all of the test methods in the class
     * @param args String[] array containing command line parameters
     * @return void
     */
    class boundedObject {
        String error;
        boundedObject (String error) {
            this.error = error;
        }
    }
     public static void main ( String [] args ) {
        test_insert();              // 3 tests
        test_retrieve();            // 3 tests
     }
     
    /**
     * test method to test out the operation of the insert method from BoundedBuffer
     */
     public static void  test_insert() {
        boundedObject oofTesterOne = new boundedObject("");
        boundedObject oofTesterTwo = new boundedObject("oof");
        System.out.println( "\n3 TESTS FOR insert():" );
        System.out.print( "   Test if empty: " );
        oofTesterOne.insert(oofTesterOne);
        try { System.out.println( oofTesterOne.length == 0 ? "true" : "false" ); }
        catch( Exception e ) { System.out.println ( false ); }
        oofTesterOne.insert(oofTesterTwo);
        System.out.print( "   Test if length is 3: " );
        try { System.out.println( oofTesterTwo.length == 3 ? "true" : "false" ); }
        catch( Exception e ) { System.out.println ( false ); }
        oofTesterOne.insert(oofTesterTwo).insert(oofTesterTwo);
        System.out.print( "   Test if length is 6: " );
        try { System.out.println( oofTesterTwo.length == 6 ? "true" : "false" ); }
        catch( Exception e ) { System.out.println ( false ); }
     }
  
    /**
     * test method to test out the operation of the retrieve method from BoundedBuffer
     */
     public static void test_retrieve() {
        boundedObject oofTesterOne = new boundedObject("");
        boundedObject oofTesterTwo = new boundedObject("oof");
        boundedObject oofTesterThree = new boundedObject();
        System.out.println( "\n3 TESTS FOR retrieve():" );
        System.out.print( "   Test for retrieving nothing: " );
        try { System.out.println( oofTesterOne.retrieve() == "" ? "true" : "false" ); }
        catch( Exception e ) { System.out.println ( false ); }
        System.out.print( "   Test for retrieving my oof: " );
        try { System.out.println( oofTesterTwo.retrieve() == "oof" ? "true" : "false" ); }
        catch( Exception e ) { System.out.println ( false ); }
        System.out.print( "   Test for retrieving null: " );
        try { System.out.println( oofTesterThree.retrieve() == null ? "true" : "false" ); }
        catch( Exception e ) { System.out.println ( false ); }
     }
}