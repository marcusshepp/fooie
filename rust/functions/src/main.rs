fn main(){
	let mut x = 17;
	println!("x = {} ", x);
	x = my_func();
	println!("x = {} ", x);
	let mut foo:i32 = calc(12, 12);
	println!("foo = {}", foo);
}

fn my_func() -> i32{
	let y:i32 = 123;
	y
}

fn calc(x:i32, y:i32) -> i32 {
	let result = x * y;
	result
}
