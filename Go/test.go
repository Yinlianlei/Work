package main

import "fmt"

func test_Select()  {
	fmt.Println("Select:")
	var c1, c2, c3 chan int
	var i1, i2 int
	c3 = make(chan int,2)
	c3<-3
	i2 = 1
   	go func(){
		c3<-3
		c3<-2
		for {
		select {
      		case i1 = <-c1:
        	 	fmt.Println("received ", i1, " from c1")
     	 	case c2 <- i2:
         		fmt.Println("sent ", i2, " to c2")
     	 	case <-c3:  // same as: i3, ok := <-c3
				 fmt.Println("received ", 233, " from c3")
				 return
	      	default:
				 fmt.Printf("no communication\n")
				 return
		   }    
		}
	}()
	c4,c5 := <-c3,<-c3
	fmt.Println(c4,c5)
}