defmodule KitchenCalculator do
  @type units :: :milliters | :fluid_ounce | :fluid_ounce | :tablespoon | :teaspoon
  @type kitchen_units :: {units, number}

  @cup_conversion 240
  @fluid_conversion 30
  @teaspoon_conversion 5
  @tablespoon_conversion 15

  @spec get_volume({atom, number}) :: number
  def get_volume({_unit, number}), do: number

  @spec to_milliliter(kitchen_units) :: {:milliliter, number}
  def to_milliliter({:milliliter, num}), do: {:milliliter, num}
  def to_milliliter({:cup, num}), do: {:milliliter, num * @cup_conversion}
  def to_milliliter({:fluid_ounce, num}), do: {:milliliter, num * @fluid_conversion}
  def to_milliliter({:teaspoon, num}), do: {:milliliter, num * @teaspoon_conversion}
  def to_milliliter({:tablespoon, num}), do: {:milliliter, num * @tablespoon_conversion}

  @spec from_milliliter({:milliter, number}, units) :: kitchen_units
  def from_milliliter(milliter_tuple, :milliliter), do: {:milliliter, get_volume(milliter_tuple)}

  def from_milliliter(milliter_tuple, :cup),
    do: {:cup, get_volume(milliter_tuple) / @cup_conversion}

  def from_milliliter(milliter_tuple, :fluid_ounce),
    do: {:fluid_ounce, get_volume(milliter_tuple) / @fluid_conversion}

  def from_milliliter(milliter_tuple, :teaspoon),
    do: {:teaspoon, get_volume(milliter_tuple) / @teaspoon_conversion}

  def from_milliliter(milliter_tuple, :tablespoon),
    do: {:tablespoon, get_volume(milliter_tuple) / @tablespoon_conversion}

  @spec convert(kitchen_units, units) :: kitchen_units
  def convert(volume_pair, unit) do
    volume_pair
    |> to_milliliter
    |> from_milliliter(unit)
  end
end
