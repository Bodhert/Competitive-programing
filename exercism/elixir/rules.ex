defmodule Rules do
  @spec eat_ghost?(boolean, boolean) :: boolean
  def eat_ghost?(power_pellet_active, touching_ghost), do:
      power_pellet_active and touching_ghost


  @spec score?(boolean, boolean) :: boolean
  def score?(touching_power_pellet, touching_dot), do:
    touching_power_pellet or touching_dot

  @spec lose?(boolean, boolean) :: boolean
  def lose?(power_pellet_active, touching_ghost), do:
    not power_pellet_active and touching_ghost

  @spec win?(boolean, boolean, boolean) :: boolean
  def win?(has_eaten_all_dots, power_pellet_active, touching_ghost), do:
    has_eaten_all_dots and not lose?(power_pellet_active, touching_ghost)
end
