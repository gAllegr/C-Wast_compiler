(module
  (import "console" "log" (func $log (param i32) (param i32)))
  (import "js" "mem" (memory 1))
  (global $a i32 (i32.const 0))
  (data (i32.const 0) "d")
  (data (i32.const 50) "b")
  (func (export "main") (result i32)
    (local $cond i32)
    (local $c i32)
    (local $b i32)
    (local $d i32)

    (set_local $cond (i32.const 5))
    (set_local $c (i32.const 2))    

    (if (i32.gt_s (get_local $cond) (i32.const 5)) 
        (then 
            (if (i32.ge_s (get_local $c) (i32.const 2))  
                (then   
                    (set_local $d (i32.const 0)
                    (call $log
                        (get_local $d)
                        (i32.const 1)
                    )
                    )
                )
            )
        )
        (else   
            (set_local $b (i32.const 50))
            (call $log
                (get_local $b)
                (i32.const 1)
            )
        )
    )
    

    (return (i32.const 0))
  )
)