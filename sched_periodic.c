static inline struct task_struct *sp_task_of(struct sched_rt_entity *rt_se)
{
	return container_of(rt_se, struct task_struct, rt);
}

static inline int on_sp_rq(struct sched_rt_entity *rt_se)
{
	return !list_empty(&rt_se->run_list);
}



static void prio_changed_sp(struct rq *rq, struct task_struct *p,
			    int oldprio, int running)
{
	
}
static void switched_to_sp(struct rq *rq, struct task_struct *p,
			   int running)
{
}


static void check_preempt_curr_sp(struct rq *rq, struct task_struct *p)
{
	//if (p->prio < rq->curr->prio)
		//resched_task(rq->curr);
}



#define for_each_leaf_sp_rq(sp_rq, rq) \
	list_for_each_entry(sp_rq, &rq->leaf_sp_rq_list, leaf_sp_rq_list)

static inline struct rq *rq_of_sp_rq(struct sp_rq *sp_rq)
{
	return sp_rq->rq;
}

static inline struct sp_rq *rt_sp_of_se(struct sched_rt_entity *rt_se)
{
	return rt_se->sp_rq;
}


static void enqueue_task_sp(struct rq *rq, struct task_struct *p, int wakeup)
{
	struct sched_rt_entity *rt_se = &p->rt;

	if (wakeup)
		rt_se->timeout = 0;
	struct sp_rq *sp_rq = rt_sp_of_se(rt_se);
	struct task_struct *curr = rq_of_sp_rq(sp_rq)->curr;
	int i;
		
struct Sched_Periodic_List *mylist = getmyList();
 int counter = getCounter();
 int loopCounter = getLoopcounter();
 //printk("Loop counter is %d \n",loopCounter);
 
 for(i=0;i<loopCounter;i++){
 	if(mylist[i].task){
	 if(mylist[i].task->pid==p->pid && mylist[i].status!=RUNNING){
		 mylist[i].status = RUNNING;
		 mylist[i].p = p->p;
		 mylist[i].c = p->c;
		 counter=counter+1;
		 setCounter(counter);
		 quicksort(mylist,0,counter);
		 }
		 }//end of if
	 
 }	
	
}


static void dequeue_task_sp(struct rq *rq, struct task_struct *p, int sleep)
{
struct sched_rt_entity *rt_se = &p->rt;
struct sp_rq *sp_rq = rt_sp_of_se(rt_se);
struct task_struct *curr = rq_of_sp_rq(sp_rq)->curr;
	
struct Sched_Periodic_List *mylist = getmyList();
 int counter = getCounter();
 //printk("I am in Class Dequeue From get counter finction I got counter as %d \n",counter);
 int i;
 for(i=0;i<counter;i++){
	 if(mylist[i].task->pid==p->pid){
		 mylist[i].status = WAITING;
		 mylist[i].p = 10000000;
		 mylist[i].c = 0;
		 quicksort(mylist,0,counter);
		 counter=counter-1;
		 setCounter(counter);
		 //printk("Now counter is %d \n",counter);
		 }
	 
 }
 printk("After dequeue sorted list is \n");
 for(i=0;i<counter;i++){
	printk("P=%d C=%d Status=%d \n",mylist[i].task->rt.run_time,mylist[i].task->rt.time_slice,mylist[i].status);
	}

}



static void yield_task_sp(struct rq *rq)
{
struct Sched_Periodic_List *mylist = getmyList();
 int counter = getCounter();
 int i;
 if(rq->curr->policy==6){
 for(i=0;i<counter;i++){	
 if(rq->curr->pid==mylist[i].task->pid){
 printk("Yielding task after %d MilliSecond\n",mylist[i].c-mylist[i].task->rt.time_slice);
 mylist[i].task->rt.time_slice=mylist[i].c;
 mylist[i].status=SLEEPING; 
 set_tsk_need_resched(mylist[i].task);
 break;
 }
 }
 }
}



/*
 * Preempt the current task with a newly woken task if needed:
 */

//Added by yogesh to return most eligible task to run
static struct task_struct *my_pick_next_task_sp(struct rq *rq){
struct Sched_Periodic_List *mylist = getmyList();
struct task_struct *curr = rq->curr;
 int counter = getCounter();
 int i;
 for(i=0;i<counter;i++){
 //if(mylist[i].task->rt.run_time<0 && mylist[i].task->rt.time_slice>0)
 //printk("There is a deadline Miss for pid %d \n",mylist[i].task->pid);
  //For the very first time return the process imidiatly
 //if(curr->policy==6){
 //if(mylist[i].task->pid!=curr->pid && mylist[i].p<curr->p && mylist[i].status==RUNNING)
 //{
 //printk("Pre-empting task with period %d \n",curr->p);
 //return mylist[i].task; 
 //}
 //}
 //if(mylist[i].status==RUNNING && mylist[i].justAdded==1){
// mylist[i].justAdded=0;
 //for(i=0;i<counter;i++){
 //if(mylist[i].task->pid==curr->pid)
 //if(mylist[i].status==SLEEPING && curr->rt.time_slice>0)
 //mylist[i].status=RUNNING; 
 //}	
 //return mylist[i].task;
 //} 
 if(mylist[i].status==RUNNING){
 return mylist[i].task;
 }
  //if(mylist[i].task->rt.run_time<=0){ 
 //printk("Before run time and time slice was %d and %d \n",mylist[i].task->rt.time_slice,mylist[i].task->rt.run_time);
 //mylist[i].timeTaken=rq->clock+mylist[i].p;
 //mylist[i].task->rt.run_time = mylist[i].p;
// mylist[i].task->rt.time_slice = mylist[i].c;
 //mylist[i].status=RUNNING;
//printk("Returning process with pid %d \n ",mylist[i].task->pid);
//printk("After run time and time slice was %d and %d \n",mylist[i].task->rt.time_slice,mylist[i].task->rt.run_time);
 //return mylist[i].task;
 //}
 } 
return NULL;
}


//**************************************** End of Add ********** 


static void put_prev_task_sp(struct rq *rq, struct task_struct *p)
{
	//update_curr_sp(rq);
	//p->se.exec_start = 0;
}





//Added by yogesh to update time slice and time period at each time tick


static void my_task_tick(struct rq *rq, struct task_struct *p, int queued){
--p->rt.time_slice;
if(p->rt.time_slice>0){
//printk("pid %d is running time left %d run time is %d \n ",p->pid,p->rt.time_slice,p->rt.run_time);
return;
}
struct Sched_Periodic_List *mylist = getmyList();
 int counter = getCounter();
 int i;
for(i=0;i<counter;i++){
 if(mylist[i].task->pid==p->pid){
 //printk("Putting Period %d process to sleep \n",mylist[i].p);
 mylist[i].status=SLEEPING;
 set_tsk_need_resched(mylist[i].task);
 }
}	

}

//***********************************end of update ******************

static void set_curr_task_sp(struct rq *rq)
{
	struct task_struct *p = rq->curr;

	p->se.exec_start = rq->clock;
}
static void sched_periodic_name(void){
printk("I am Sched Periodic class \n");
}



static const struct sched_class periodic_sched_class = {
	.next			= &rt_sched_class,
	.enqueue_task		= enqueue_task_sp,
	.dequeue_task		= dequeue_task_sp,
	.yield_task		= yield_task_sp,
	.check_preempt_curr	= check_preempt_curr_sp,
	//.pick_next_task		= pick_next_task_sp,
	.pick_next_task		= my_pick_next_task_sp,
	.put_prev_task		= put_prev_task_sp,
	.set_curr_task          = set_curr_task_sp,
	//.task_tick		= task_tick_sp,
	.task_tick			= my_task_tick,
	.prio_changed		= prio_changed_sp,
	.switched_to		= switched_to_sp,
	.name             = sched_periodic_name,
};
