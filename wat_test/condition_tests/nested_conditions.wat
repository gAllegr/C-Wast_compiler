(module
  (import "console" "log" (func $log (param i32) (param i32)))
  (import "js" "mem" (memory 1))
  (data (i32.const 0) "NOT of AND conditions")
  (data (i32.const 50) "NOT of OR conditions")
  (data (i32.const 100) "AND of a NOT cond and a simple cond")
  (data (i32.const 150) "OR of a AND cond and a simple cond")
  (data (i32.const 200) "NOT of OR conditions")
  (data (i32.const 250) "OR of a AND cond and a simple cond")
  (func (export "main") 
    (local $cond i32)
    (set_local $cond (i32.const 5))

    ( if (i32.eqz (i32.and (i32.lt_s (get_local $cond) (i32.const 7)) (i32.gt_s (get_local $cond) (i32.const 3))))   
        (then   
            (call $log
                (i32.const 0)
                (i32.const 21)
            )
        )
    )

    ( if (i32.eqz (i32.or (i32.gt_s (get_local $cond) (i32.const 2)) (i32.lt_s (get_local $cond) (i32.const 1))))   
        (then   
            (call $log
                (i32.const 50)
                (i32.const 20)
            )
        )
    )

    ( if (i32.and (i32.eq (i32.eqz (get_local $cond)) (i32.const 5)) (i32.lt_s (get_local $cond) (i32.const 6)))   
        (then   
            (call $log
                (i32.const 100)
                (i32.const 35)
            )
        )
    )

    ( if (i32.or (i32.and (i32.lt_s (get_local $cond) (i32.const 7)) (i32.gt_s (get_local $cond) (i32.const 3))) (i32.lt_s (get_local $cond) (i32.const 6)))   
        (then   
            (call $log
                (i32.const 150)
                (i32.const 34)
            )
        )
    )

    ( if (i32.or (i32.gt_s (i32.eqz (get_local $cond)) (i32.const 2)) (i32.lt_s (get_local $cond) (i32.const 1)))
        (then   
            (call $log
                (i32.const 200)
                (i32.const 20)
            )
        )
    )

    ( if (i32.or (i32.and (i32.lt_s (get_local $cond) (i32.const 7)) (i32.gt_s (get_local $cond) (i32.const 3))) (i32.lt_s (get_local $cond) (i32.const 6)))
        (then   
            (call $log
                (i32.const 250)
                (i32.const 34)
            )
        )
    )

    (return (i32.const 0))
  )
)