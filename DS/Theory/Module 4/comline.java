class Sample
{
	public static void main(String args[])
	{
		int nums[] = new int[args.length];
		//how is that working w/o brackets?
		for(int i=0; i<args.length; i++)
		{
			System.out.println(args[i]);
			nums[i] = Integer.parseInt(args[i]);
		}
	int temp = -1;
	for (int i = 0; i<nums.length; i++)
	{
		for (int j=0; j<nums.length-1-i;j++)
		{
			if (nums[j]>nums[j+1])
			{
				temp = nums[j];
				nums[j]=nums[j+1];
				nums[j+1]=temp;
			}
		}
	}
	for(int i=0; i<nums.length; i++)
	{
		System.out.println(nums[i]);
	}

	}	
}
