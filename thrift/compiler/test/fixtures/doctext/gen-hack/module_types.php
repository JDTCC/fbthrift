<?hh
/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

/**
 * This enum is great
 * 
 * Original thrift enum:-
 * B
 */
enum B: int {
  /**
   * EnumDef doctext.
   */
  HELLO = 0;
}

class B_TEnumStaticMetadata implements \IThriftEnumStaticMetadata {
  public static function getEnumMetadata()[]: \tmeta_ThriftEnum {
    return tmeta_ThriftEnum::fromShape(
      shape(
        "name" => "module.B",
        "elements" => dict[
          0 => "HELLO",
        ],
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TEnumAnnotations {
    return shape(
      'enum' => dict[],
      'constants' => dict[
      ],
    );
  }
}

/**
 * DefinitionList doctext.
 *
 * Original thrift struct:-
 * A
 */
class A implements \IThriftSyncStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'useless_field',
      'type' => \TType::I32,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'useless_field' => 1,
  ];

  const type TConstructorShape = shape(
    ?'useless_field' => ?int,
  );

  const int STRUCTURAL_ID = 4169556808001627706;
  /**
   * Field doctext.
   * 
   * Original thrift field:-
   * 1: i32 useless_field
   */
  public int $useless_field;

  public function __construct(?int $useless_field = null)[] {
    $this->useless_field = $useless_field ?? 0;
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
      Shapes::idx($shape, 'useless_field'),
    );
  }

  public function getName()[]: string {
    return 'A';
  }

  public function clearTerseFields()[write_props]: void {
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "module.A",
        "fields" => vec[
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 1,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_I32_TYPE,
                )
              ),
              "name" => "useless_field",
            )
          ),
        ],
        "is_union" => false,
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
      ],
    );
  }

  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

}

enum UEnum: int {
  _EMPTY_ = 0;
  i = 1;
  s = 2;
}

/**
 * Union U
 *
 * Original thrift struct:-
 * U
 */
class U implements \IThriftSyncStruct, \IThriftUnion<UEnum> {
  use \ThriftUnionSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'i',
      'union' => true,
      'type' => \TType::I32,
    ),
    2 => shape(
      'var' => 's',
      'union' => true,
      'type' => \TType::STRING,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'i' => 1,
    's' => 2,
  ];

  const type TConstructorShape = shape(
    ?'i' => ?int,
    ?'s' => ?string,
  );

  const int STRUCTURAL_ID = 3963907419268179345;
  /**
   * i32 field i
   * 
   * Original thrift field:-
   * 1: i32 i
   */
  public ?int $i;
  /**
   * string s
   * 
   * Original thrift field:-
   * 2: string s
   */
  public ?string $s;
  protected UEnum $_type = UEnum::_EMPTY_;

  public function __construct(?int $i = null, ?string $s = null)[] {
    $this->_type = UEnum::_EMPTY_;
    if ($i !== null) {
      $this->i = $i;
      $this->_type = UEnum::i;
    }
    if ($s !== null) {
      $this->s = $s;
      $this->_type = UEnum::s;
    }
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
      Shapes::idx($shape, 'i'),
      Shapes::idx($shape, 's'),
    );
  }

  public function getName()[]: string {
    return 'U';
  }

  public function getType()[]: UEnum {
    return $this->_type;
  }

  public function reset()[write_props]: void {
    switch ($this->_type) {
      case UEnum::i:
        $this->i = null;
        break;
      case UEnum::s:
        $this->s = null;
        break;
      case UEnum::_EMPTY_:
        break;
    }
    $this->_type = UEnum::_EMPTY_;
  }

  public function set_i(int $i)[write_props]: this {
    $this->reset();
    $this->_type = UEnum::i;
    $this->i = $i;
    return $this;
  }

  public function get_i()[]: ?int {
    return $this->i;
  }

  public function getx_i()[]: int {
    invariant(
      $this->_type === UEnum::i,
      'get_i called on an instance of U whose current type is %s',
      (string)$this->_type,
    );
    return $this->i as nonnull;
  }

  public function set_s(string $s)[write_props]: this {
    $this->reset();
    $this->_type = UEnum::s;
    $this->s = $s;
    return $this;
  }

  public function get_s()[]: ?string {
    return $this->s;
  }

  public function getx_s()[]: string {
    invariant(
      $this->_type === UEnum::s,
      'get_s called on an instance of U whose current type is %s',
      (string)$this->_type,
    );
    return $this->s as nonnull;
  }

  public function clearTerseFields()[write_props]: void {
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "module.U",
        "fields" => vec[
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 1,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_I32_TYPE,
                )
              ),
              "name" => "i",
            )
          ),
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 2,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_STRING_TYPE,
                )
              ),
              "name" => "s",
            )
          ),
        ],
        "is_union" => true,
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
      ],
    );
  }

  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

}

/**
 * Something amiss
 *
 * Original thrift exception:-
 * Bang
 */
class Bang extends \TException implements \IThriftSyncStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'message',
      'type' => \TType::STRING,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'message' => 1,
  ];

  const type TConstructorShape = shape(
    ?'message' => ?string,
  );

  const int STRUCTURAL_ID = 2427562471238739676;
  /**
   * All explosions can be explained away
   * 
   * Original thrift field:-
   * 1: string message
   */
  public string $message;

  public function __construct(?string $message = null)[] {
    parent::__construct();
    $this->message = $message ?? '';
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
      Shapes::idx($shape, 'message'),
    );
  }

  public function getName()[]: string {
    return 'Bang';
  }

  public function clearTerseFields()[write_props]: void {
  }

  public static function getExceptionMetadata()[]: \tmeta_ThriftException {
    return tmeta_ThriftException::fromShape(
      shape(
        "name" => "module.Bang",
        "fields" => vec[
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 1,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_STRING_TYPE,
                )
              ),
              "name" => "message",
            )
          ),
        ],
      )
    );
  }

  public static function getAllStructuredAnnotations()[write_props]: \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
      ],
    );
  }

  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

}

