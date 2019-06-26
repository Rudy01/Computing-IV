how you implemented the ring buffer (e.g. per the Princeton guidance, or some other way)
    In the Ring Buffer assignment, I used Princeton's website for guidance. I found that implemented the size, empty, and the peek was very easy.  While the enqueue (adding an item the end) and the dequeue (deleting an item from the front) was the most difficult part to implement. But I referred to the queue code that was provided to me in Computing II to implement the enqueue and dequeue. I also threw some exceptions in the constructor, enqueue, dequeue, and peek. In the throw exceptions, throws away the edge cases, for example, if the capacity entered is less than 0 or checking if the ring buffer is empty or full.

exactly what works or doesn't work 
	everything works
