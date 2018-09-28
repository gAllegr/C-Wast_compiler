(module
  (import "console" "log" (func $log (param i32) (param i32)))
  (import "js" "mem" (memory 1))
  (data (i32.const 0) "Variable has a value lesser then or equal to 5")
  (data (i32.const 50) "a")
  (func (export "main") 
    (local $cond i32)
    (local $a i32)

    (set_local $cond (i32.const 5))   

    (if (i32.gt_s (get_local $cond) (i32.const 5)) 
        (then 
            (set_local $a (i32.const 50))
            (call $log
                (get_local $a)
                (i32.const 1)
            )
        )
        (else  
            (call $log
                (i32.const 0)
                (i32.const 46)
            )
        )
    )

    (return (i32.const 0))
  )
)