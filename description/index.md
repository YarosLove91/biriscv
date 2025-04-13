# Описание

В данном каталоге представлено описание модулей riscv_top и riscv_tcm_top.

# riscv_top

Подробное описание модуля приведено в файле [riscv_top.md](/description/riscv_top.md)

Данный модуль имеет следующую иерархическую структуру:

- riscv_top
  - riscv_core
    - issue
      - trace_sim
      - regfile
      - pipe_ctrl
    - frontend
      - npc
      - fetch
      - decode
    - exec
    - multiplier
    - csr
    - lsu
    - mmu
    - divider
  - icache
    - data_ram
    - reg_ram
  - dcache
    - dcache_core
      - dcache_core_data_ram
      - dcache_core_tag_ram
    - dcache_axi
      - dcache_axi_fifo
      - dcache_axi_axi
    - dcache_mux
    - dcache_ifpem_mux
    - dcache_ifpem

Также со структурой riscv_top можно охнакомиться на диаграмме:
![riscv_top.png](/description/riscv_top.png)

# riscv_tcm_top

Подробное описание модуля приведено в файле [riscv_tcm_top.md](/description/riscv_tcm_top.md)

Данный модуль имеет следующую иерархическую структуру:

- riscv_tcm_top
  - riscv_core
    - issue
      - trace_sim
      - regfile
      - pipe_ctrl
    - frontend
      - npc
      - fetch
      - decode
    - exec
    - multiplier
    - csr
    - lsu
    - mmu
    - divider
  - icache
    - data_ram
    - reg_ram
  - dport_mux
  - dport_axi
  - tcm_mem
    - tcm_mem_ram
    - tcm_mem_pmem

Также со структурой riscv_tcm_top можно охнакомиться на диаграмме:
![riscv_tcm_top.png](/description/riscv_tcm_top.png)