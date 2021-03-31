<?php
class Task extends Threaded
{
    private $value;
    private $j;
    public function __construct(int $i)
    {
	$a = array(1.0, 2.0, 3.0, 4.0);
	$ar = array(1.0, 4.0, 9.0, 16.0);
	$arr[] = 4;
	$m = 0.0; $d = 0.0; $m_in_2 = 0.0; $m_2_in = 0.0;
	for($i = 0;$i < 4;$i++)
	{
		$arr[$i] = (rand(1, 10)) / 10.0;
	}
	for($i = 0;$i < 4;$i++)
	{
		$m = $m + $a[$i] * $arr[$i];
	}
	$m_2_in = $m * $m;
	for($i = 0;$i < 4;$i++)
	{
		$m_in_2 = $m_in_2 + $ar[$i] * $arr[$i];
	}
	$d = $m_in_2 - $m_2_in;
	$this->value = $m; //mathswait
	$this->j = $d;	 //disperce
    }

    public function run()
    {
       $s=0;
       for ($i=0; $i<4; $i++)
       {
            $s++;
        }
        echo "mathswait: {$this->value}\n";
	echo "disperce: {$this->j}\n";
    }
}

# Create a pool of 4 threads
$pool = new Pool(4);
for ($i = 0; $i < 4; ++$i)
{
    $pool->submit(new Task($i));
}
while ($pool->collect());
$pool->shutdown();

